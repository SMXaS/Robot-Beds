#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);
#define DHTPIN  A1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
#include <SPI.h>
#include <Wire.h>
#define CommonSenseMetricSystem

#define trigPin 3
#define echoPin 2

char temperature[] = "00.0 C";
char humidity[]    = "00.0 %";
 
void setupDHT(void) {
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  dht.begin();
  delay(2000);
  display.clearDisplay();
  display.drawFastHLine(0, 32, SSD1306_LCDWIDTH, WHITE);
}
 
void DHT_DISPLAY(void) {
  display.clearDisplay();
  byte RH = dht.readHumidity();
  byte Temp = dht.readTemperature();
 
  temperature[0] = Temp / 10 + 48;
  temperature[1] = Temp % 10 + 48;
  humidity[0]    = RH / 10 + 48;
  humidity[1]    = RH % 10 + 48;
  
  display.setTextSize(1.5);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(3, 5);
  display.print("TEMPERATURE:");
  display.setCursor(3, 15);
  display.print("HUMIDITY:");
  display.setCursor(25, 45);
  display.print("Arnoldas Jurkus");
  display.setCursor(50, 55);
  display.print("1801809");
  display.display();
  display.setCursor(80, 5);
  display.print(temperature);
  display.setCursor(80, 15);
  display.print(humidity);
  display.display();
  delay(1000);
}



void setup1(void) {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
}

void loop1(void) {
  //display.clearDisplay();
  long duration, distance;

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

#ifdef CommonSenseMetricSystem
  distance = (duration / 2) / 29.1;
#endif
  display.setCursor(3, 5);
  display.setTextSize(2.5);
  display.setTextColor(WHITE);
  display.println(distance);
  display.setCursor(80, 5);
  display.setTextSize(2.5);

#ifdef CommonSenseMetricSystem
  display.println("cm");
#endif
  display.display();
  delay(500);
  display.clearDisplay();
  Serial.println(distance);
}
