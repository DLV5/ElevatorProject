#include "Arduino.h"
#include "Elevator.h"
#include "InputHandler.h"

InputHandler::InputHandler(){
  pinMode(_elevatorFloorButtonPins[0], INPUT_PULLUP);
  pinMode(_elevatorFloorButtonPins[1], INPUT_PULLUP);
  pinMode(_elevatorFloorButtonPins[2], INPUT_PULLUP);
}

uint8_t* InputHandler::getPins(){
  return _elevatorFloorButtonPins;
}

uint8_t InputHandler::calculateVoltageBasedOnUltrasonicData(uint16_t sensorData, uint8_t targetFloor, uint8_t currentFloor){
  // 1930 - max pulse value -> about 32cm bottom position
  uint8_t maxVoltage = 255;
  uint8_t returnValueDegrees;

  // from first floor to the second
  switch (targetFloor) {
  case 1:
    if(currentFloor == 1) return;
    if(currentFloor == 2) returnValueDegrees = map(sensorData, 940, 1530, 255, 0);
    if(currentFloor == 3) returnValueDegrees = map(sensorData, 460, 1530, 255, 0);
    break;
  //Move to second floor
  case 2:
    if(currentFloor == 1) returnValueDegrees = map(sensorData, 1530, 970, 255, 0);
    if(currentFloor == 2) return;
    if(currentFloor == 3) returnValueDegrees = map(sensorData, 460, 970, 150, 255);
    break;
  // move to third
  case 3:
    if(currentFloor == 1) returnValueDegrees = map(sensorData, 1530, 550, 150, 255);
    if(currentFloor == 2) returnValueDegrees = map(sensorData, 940, 550, 150, 255);
    if(currentFloor == 3) return;
    break;
  }

  //return sin(returnValueDegrees * PI/180) * maxVoltage;
  return 150;
}

