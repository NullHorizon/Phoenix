#include "driving.h"

Driving::Driving(Motor &motor_left, Motor &motor_right) : motor_left(motor_left), motor_right(motor_right) {
  //
}

void Driving::setup() {
  
}

void Driving::goForward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("BCK");
  this->motor_left.setPower(POWER);
  this->motor_right.setDirection("FWD");
  this->motor_right.setPower(POWER);  
}

void Driving::goRightForward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("FWD");
  this->motor_left.setPower(POWER);  
  this->motor_right.setPower(0);
}

void Driving::goRightBackward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("BCK");
  this->motor_left.setPower(POWER);  
  this->motor_right.setPower(0);
}

void Driving::goLeftForward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setPower(0);
  this->motor_right.setDirection("FWD");
  this->motor_right.setPower(POWER);
}

void Driving::goLeftBackward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setPower(0);
  this->motor_right.setDirection("BCK");
  this->motor_right.setPower(POWER);
}

void Driving::goBackward() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("FWD");
  this->motor_left.setPower(POWER);
  this->motor_right.setDirection("BCK");
  this->motor_right.setPower(POWER);
}

void Driving::goLeft() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("FWD");
  this->motor_left.setPower(POWER);
  this->motor_right.setDirection("FWD");
  this->motor_right.setPower(POWER);
}

void Driving::goRight() {
  if (critical_range) {
    return;
  }
  this->motor_left.setDirection("BCK");
  this->motor_left.setPower(POWER);
  this->motor_right.setDirection("BCK");
  this->motor_right.setPower(POWER);
}

void Driving::stop() {
  this->motor_left.setPower(0);
  this->motor_right.setPower(0);
}


