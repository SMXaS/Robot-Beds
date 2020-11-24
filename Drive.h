
class Drive {
    int _Motor_Left_One;
    int _Motor_Left_Two;
    int _Motor_Right_One;
    int _Motor_Right_Two;

  public:
    Drive(int Motor_Left_One, int Motor_Left_Two, int Motor_Right_One, int Motor_Right_Two) {

      _Motor_Left_One = Motor_Left_One;
      _Motor_Left_Two = Motor_Left_Two;
      _Motor_Right_One = Motor_Right_One;
      _Motor_Right_Two = Motor_Right_Two;

      pinMode(_Motor_Left_One, OUTPUT);
      pinMode(_Motor_Left_Two, OUTPUT);
      pinMode(_Motor_Right_One, OUTPUT);
      pinMode(_Motor_Right_Two, OUTPUT);

    }

    void Forward() {
      digitalWrite(_Motor_Left_One, HIGH);
      digitalWrite(_Motor_Left_Two, LOW);
     
      
      digitalWrite(_Motor_Right_One, HIGH);
      digitalWrite(_Motor_Right_Two, LOW);
    }
    
    void Back() {
      digitalWrite(_Motor_Left_One, LOW);
      digitalWrite(_Motor_Left_Two, HIGH);

      digitalWrite(_Motor_Right_One, LOW);
      digitalWrite(_Motor_Right_Two, HIGH);
    }
    
    void Stop() {
      digitalWrite(_Motor_Left_One, LOW);
      digitalWrite(_Motor_Left_Two, LOW);

      digitalWrite(_Motor_Right_One, LOW);
      digitalWrite(_Motor_Right_Two, LOW);
    }
    
     void Left() {
      digitalWrite(_Motor_Left_One, LOW);
      digitalWrite(_Motor_Left_Two, HIGH);

      digitalWrite(_Motor_Right_One, HIGH);
      digitalWrite(_Motor_Right_Two, LOW);
    }

    void Right() {
      digitalWrite(_Motor_Left_One, HIGH);
      digitalWrite(_Motor_Left_Two, LOW);

      digitalWrite(_Motor_Right_One, LOW);
      digitalWrite(_Motor_Right_Two, HIGH);
    }
     
};
