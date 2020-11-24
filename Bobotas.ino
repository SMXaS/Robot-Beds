#include "Drive.h"
#include "Buzzer.h"
#include "LED.h"
#include "Button.h"
#include "LDR.h"
#include "Ultrasonic.h"
#include "TemperatureHumidity.h"
#include "OLEDwDHT.h"
#include "OLED.h"
#include "OLEDwULTRA.h"
//#include "DHTwULTRA.h"
#define Motor_Left_One 12
#define Motor_Left_Two 11
#define Motor_Right_One 10
#define Motor_Right_Two 9

//Variables of Drive


//Variables of LED
int redPIN = 6;
int bluePIN = 8;

//Variables of LDR
int Left_LDR = A0;
int Right_LDR = A7;

//Variables of Ultrasonic
int triggerPIN = 3;
int echoPIN = 2;

//Variables of Buzzer
int buzzerPIN = 13;

//Variables of Humidity and Temperature
int temperaturePIN = A1;

//Variables of Button
int buttonPIN = 4;

//Variables of OLED
int clockPIN = A6;
int dataPIN = A5;

//Objects of Drive
Drive drive (Motor_Left_One, Motor_Left_Two, Motor_Right_One, Motor_Right_Two);

//Objects of Buzzer
Buzzer buzzer(buzzerPIN);

//Objects of LED
LED led(bluePIN, redPIN);

//Objects of Button
Button button (buttonPIN);

//Objects of LDR
LDR ldr (Left_LDR, Right_LDR);

//Objects of Ultrasonic
Ultrasonic ultrasonic(triggerPIN, echoPIN);

//Objects of Humidity and Temperature
TemperatureHumidity temperaturehumidity(temperaturePIN);

//Objects of OLED
OLED oled (clockPIN, dataPIN);




void setup()
{
  //setupDHT();

  //setup1();

}

void loop()
{
 
 
  
  
  //Drive
  //drive.Back();
  //delay(1000);
  //drive.Forward();
  //delay(1000);

  //LED + button
  //if(button.isPressed()){
  //led.blue();
  //}else {
  //led.red();
  //}

  //LED with no button
  //led.blue();
  //led.red();

  //Buzzer
  //buzzer.PlaySound();

  //LDR with LED
  /*
       int ldrStatus_Left = analogRead(Left_LDR);
       int ldrStatus_Right = analogRead(Right_LDR);

      if (ldrStatus_Left <= 500) {

        digitalWrite(bluePIN, HIGH);
        digitalWrite(redPIN, LOW);

      }
      else if (ldrStatus_Right <= 500){
        digitalWrite(redPIN, HIGH);
        digitalWrite(bluePIN, LOW);
    }
    else if (ldrStatus_Left <= 100 && ldrStatus_Right <= 100) {
        digitalWrite(redPIN, LOW);
        digitalWrite(bluePIN, LOW);
    }else{
      return;
    }

  */

  //Ultrasonic
  //ultrasonic.Object();

  //Temperature and Humidity
  //temperaturehumidity.Humidity();

  //OLED display

  // DHT_DISPLAY();
  
  
  LDR_DRIVE();
  Left_LED_LDR();
  Right_LED_LDR();

  



  /* TODO:
      1. Sujungti OLED + Temperature & Humidity + Ultrasonic, OLED file. DONE
      2. Sujungti LDR + LED + Drive, Naujame file.
      3. Parasyti programa sitame maine, kad sektu sviesa, suradus sviesa pradeda sukinetis ar groti muzika.
      4. Bugas, negali naudoti DHT11 su motor, nes definina motor pina. 
  */
  // Left_LED_LDR();
  //delay(1000);
  ///Right_LED_LDR();

}



  void LDR_DRIVE(){
  int SensorLeft;
  int SensorRight;
  int SensorDifference;
  
  SensorLeft = 1023 - analogRead(Left_LDR);

  SensorRight = 1023 - analogRead(Right_LDR);

  SensorDifference = abs(SensorLeft - SensorRight);

  if (SensorLeft<500 && SensorRight<500) { drive.Stop();}

  if (SensorLeft > SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) {
    
  drive.Left();
  }

  if (SensorLeft < SensorRight && SensorDifference > 75 && SensorLeft>500 && SensorRight>500) { 
  
  

  drive.Right();
  }

  else if (SensorLeft>500 && SensorRight>500 && SensorDifference < 75) {

  drive.Forward();
  }
  if( SensorLeft<490 && SensorRight<490){
    buzzer.PlaySound();
delay(100);
  }
  }

/*
  void LedBrigtness(){
  int i= Left_LDR;




  analogWrite(bluePIN, Left_LDR);
  delay(1000);
  analogWrite(bluePIN, 200);
  delay(1000);
  analogWrite(bluePIN, 100);
  delay(1000);
  analogWrite(bluePIN, 50);
  delay(1000);
  analogWrite(bluePIN,0);
  delay(1000);

  }
*/

  void Left_LED_LDR(){
  int readingLeft=analogRead(Left_LDR);
  int brightLeft=readingLeft/4;
  delay(500);
  analogWrite(bluePIN, brightLeft);

  }
  //Has a problem with a circuit probably, recognizes light when its not there
  void Right_LED_LDR(){
  int readingRight=analogRead(Right_LDR);
  int brightRight=readingRight/4;
  delay(500);
  if(brightRight <= 100){
  analogWrite(redPIN, 0);
  }else{
  analogWrite(redPIN, brightRight);
  }


  }
