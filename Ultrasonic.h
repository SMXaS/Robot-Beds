#ifndef _ULTRASONIC_H
#define _ULTRASONIC_H
class Ultrasonic {

    int _Ultra_Sonic_Trigger;
    int _Ultra_Sonic_Echo;

  public:
    Ultrasonic(int Ultra_Sonic_Trigger, int Ultra_Sonic_Echo) {
      _Ultra_Sonic_Trigger = Ultra_Sonic_Trigger;
      _Ultra_Sonic_Echo = Ultra_Sonic_Echo;

    }

    void Object() {
      long duration, inches, cm;
      pinMode(_Ultra_Sonic_Trigger, OUTPUT);
      digitalWrite(_Ultra_Sonic_Trigger, LOW);
      delayMicroseconds(2);
      digitalWrite(_Ultra_Sonic_Trigger, HIGH);
      delayMicroseconds(10);
      digitalWrite(_Ultra_Sonic_Trigger, LOW);
      pinMode(_Ultra_Sonic_Echo, INPUT);
      duration = pulseIn(_Ultra_Sonic_Echo, HIGH);
      inches = microsecondsToInches(duration);
      cm = microsecondsToCentimeters(duration);
      Serial.print(inches);
      Serial.print("in, ");
      Serial.print(cm);
      Serial.print("cm");
      Serial.println();
      delay(100);
    }

    long microsecondsToInches(long microseconds) {
      return microseconds / 74 / 2;
    }

    long microsecondsToCentimeters(long microseconds) {
      return microseconds / 29 / 2;
    }
};

#endif // _ULTRASONIC_H
