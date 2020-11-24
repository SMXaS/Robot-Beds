/*
#ifndef _OLED_W_ULTRA_H
#define _OLED_W_ULTRA_H
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
//Adafruit_SSD1306 display(OLED_RESET);
#define CommonSenseMetricSystem

#define trigPin 3
#define echoPin 2




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
#endif // _OLED_W_ULTRA_H
*/
