#include "HardwareSerial.h"
#include "Arduino.h"
#include "MotorController.h"
#include "Streaming.h"

MotorController::MotorController(){
  pinMode(_pins[0], OUTPUT);
  pinMode(_pins[1], OUTPUT);
  pinMode(_pins[2], OUTPUT);

  digitalWrite(_pins[0], LOW);
  digitalWrite(_pins[1], LOW);
  digitalWrite(_pins[2], HIGH);
}

uint8_t* MotorController::getPins(){
  return _pins;
}

void MotorController::toggleMotor(){
  digitalWrite(_pins[0], !digitalRead(_pins[0]));
}

void MotorController::changeDirection(){
  digitalWrite(_pins[1], !digitalRead(_pins[1]));
  digitalWrite(_pins[2], !digitalRead(_pins[2]));

  Serial << direction << endl;

  if(digitalRead(_pins[2]) == HIGH){
    Serial << "Change direction to up" << endl;
    direction = UP;
  }
  else{
    Serial << "Change direction to down" << endl;
    direction = DOWN;
  }
}

void MotorController::setRotationSpeed(uint8_t voltage){
  if(digitalRead(_pins[1]) == HIGH){
    digitalWrite(_pins[1], voltage);
    analogWrite(_pins[2], LOW);
  } else {
    digitalWrite(_pins[1], LOW);
    analogWrite(_pins[2], voltage);
  }
}

Direction MotorController::getDirection(){
  return direction;
}