#pragma once

#include "Arduino.h"

class MotorController{
  private:
    uint8_t _pins[3] = {7, 6, 5};
  public:
    MotorController();
    uint8_t* getPins();

    void toggleMotor();
    void changeDirection();
    void setRotationSpeed(uint8_t voltage);
};