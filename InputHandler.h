#pragma once

#include "Arduino.h"

class InputHandler{
  private:
    uint8_t _elevatorFloorButtonPins[3] {A1, A2, A3};
    uint8_t _valueBehindTheButton[3] {1, 2, 3};
    //Elevator elevator;
  public:
    InputHandler();
    uint8_t* getPins();

    //void move(Elevator, _valueBehindTheButton);
    uint8_t calculateVoltageBasedOnUltrasonicData(uint16_t sensorData, uint8_t targetFloor, uint8_t currentFloor);
};