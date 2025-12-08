#pragma once

#include "Arduino.h"

class InputHandler{
  private:
    uint8_t _elevatorFloorButtonPins[3] {A1, A2, A3};
    uint8_t _valueBehindTheButton[3] {1, 2, 3};
  public:
    InputHandler();
    uint8_t* getPins();

    uint8_t calculateVoltageBasedOnUltrasonicData(uint16_t sensorData, uint8_t targetFloor, uint8_t currentFloor);
};