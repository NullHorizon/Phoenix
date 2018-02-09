#include "Motor.h"

#define POWER 100

class Driving {
  public:
    Driving(Motor &motor_left, Motor &motor_right);
    void setup();
    void goForward();
    void goLeft();
    void goRight();
    void goBackward();
    void goRightForward();
    void goRightBackward();
    void goLeftForward();
    void goLeftBackward();
    void stop();
    bool critical_range = false;  
  private:
    Motor &motor_right;
    Motor &motor_left;    
};

