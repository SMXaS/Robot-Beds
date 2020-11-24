#ifndef _LDR_H
#define _LDR_H
class LDR {

    int _Left_LDR;
    int _Right_LDR;

  public:
    LDR(int Left_LDR, int Right_LDR) {
      _Left_LDR = Left_LDR;
      _Right_LDR = Right_LDR;

      pinMode(_Left_LDR , INPUT);
      pinMode(_Right_LDR , INPUT);
    }

    void Recognize() {
 

     
    }





    /*void setup() {

      Serial.begin(9600);

      pinMode(ledPin, OUTPUT);

      pinMode(ldrPin, INPUT);

      }
    */


};

#endif // _LDR_H
