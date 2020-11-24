#ifndef _BUTTON_H
#define _BUTTON_H
class Button {
  
    int _buttonPIN;
    
  public:
    Button(int buttonPIN) {
      _buttonPIN = buttonPIN;

      pinMode(_buttonPIN, INPUT_PULLUP);
    }

    bool isPressed() {
      return !digitalRead(_buttonPIN);
    }
};

#endif // _BUTTON_H
