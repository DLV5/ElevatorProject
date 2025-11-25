#pragma once

#include "Arduino.h"

class MotorController{
  private:
    uint8_t _pins[3];
  public:
    MotorController() : _pins{1, 2, 3} {}
    uint8_t* getPins();
};