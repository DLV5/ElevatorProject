#include "HardwareSerial.h"
#include "Arduino.h"
#include "MotorController.h"

MotorController::MotorController(){
  DDRD |= (1 << _pins[0]) ||  (1 << _pins[1]) || (1 << _pins[2]);

  PORTD |= (1 << _pins[0]) ||  (1 << _pins[1]) ||  (1 << _pins[2]);
}

uint8_t* MotorController::getPins(){
  return _pins;
}

void MotorController::toggleMotor(){
  PORTD ^= 1 << _pins[0];
}

void MotorController::changeDirection(){
  PORTD ^= 1 << _pins[1];
  PORTD ^= 1 << _pins[2];

  if(bitRead(PORTD, _pins[2]) == HIGH)
    direction = UP;
  else
    direction = DOWN;
}

void MotorController::setRotationSpeed(uint8_t voltage){
  if(bitRead(PORTD, _pins[1]) == HIGH){
    bitWrite(PORTD, _pins[2], LOW);
    analogWrite(_pins[1], voltage);
  } else {
    bitWrite(PORTD, _pins[1], LOW);
    analogWrite(_pins[2], voltage);
  }
}

Direction MotorController::getDirection(){
  return direction;
}