#include "Motor.h"

int hash(const String str)
{
  const char *s = str.c_str();
  int h = 17;
  int c;
  while ((c = *s++))
    h = ((h << 5) + h) + c;
  return h;
}

Motor::Motor(int in_1, int in_2, int h_pwr) {
  this->pin_H_bridge_input_1 = in_1;
  this->pin_H_bridge_input_2 = in_2;
  this->pin_H_bridge_power = h_pwr;
  this->power = MIN_POWER;
}

void Motor::setup() {
  pinMode(this->pin_H_bridge_input_1, OUTPUT);
  pinMode(this->pin_H_bridge_input_2, OUTPUT);
  pinMode(this->pin_H_bridge_power, OUTPUT);

  analogWrite(this->pin_H_bridge_power, MIN_POWER);
}

void Motor::setPower(int pwr) {
  if (pwr < 0 || pwr > 100) {
    //throw exception
    return;
  }
  this->power = (int)(MIN_POWER + (MAX_POWER - MIN_POWER) / 100 * pwr);
  updateMotor();
}

void Motor::setDirection(String dir) {
  if(dir.length() > 3) {
    return; 
  }
  if (dir.equals("FWD") || dir.equals("BCK"))
  {
    this->direction = dir;
    updateMotor();
  }
  return;      
}

void Motor::updateMotor() {
  if (this->direction.equals("FWD")) {
      digitalWrite(pin_H_bridge_input_1, HIGH);
      digitalWrite(pin_H_bridge_input_2, LOW);
  }
  if (this->direction.equals("BCK")) {
      digitalWrite(pin_H_bridge_input_1, LOW);
      digitalWrite(pin_H_bridge_input_2, HIGH);
  }
  analogWrite(pin_H_bridge_power, power);
}

