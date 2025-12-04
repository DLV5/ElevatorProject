#pragma once

#include "Arduino.h"

enum Direction {
  UP,
  DOWN
};

class MotorController{
  private:
    uint8_t _pins[3] = {7, 6, 5};
    Direction direction = UP;
  public:
    MotorController();
    uint8_t* getPins();

    void toggleMotor();
    void changeDirection();
    void setRotationSpeed(uint8_t voltage);
    Direction getDirection();
};