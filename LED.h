#ifndef _LED_H
#define _LED_H
class LED {
  public:
  
    int _blueLED;
    int _redLED;
    
    LED(int blueLED, int redLED) {
      _blueLED = blueLED;
      _redLED = redLED;

      pinMode(_blueLED, OUTPUT);
      pinMode(_redLED, OUTPUT);
    }

    void blue() {
      digitalWrite(_blueLED, HIGH);
      digitalWrite(_redLED, LOW);
    }

    void red() {
      digitalWrite(_blueLED, LOW);
      digitalWrite(_redLED, HIGH);
    }

    void ledsOFF() {
      digitalWrite(_blueLED, LOW);
      digitalWrite(_redLED, LOW);
    }
};

#endif // _LED_H
