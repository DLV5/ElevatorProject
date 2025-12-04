#include "Elevator.h"
#include "InputHandler.h"

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
    if(currentFloor == 2) returnValueDegrees = map(sensorData, 1240, 1930, 150, 255);
    if(currentFloor == 3) returnValueDegrees = map(sensorData, 550, 1930, 150, 255);
    break;
  //Move to second floor
  case 2:
    if(currentFloor == 1) returnValueDegrees = map(sensorData, 1930, 1240, 150, 255);
    if(currentFloor == 2) return;
    if(currentFloor == 3) returnValueDegrees = map(sensorData, 550, 1240, 150, 255);
    break;
  // move to third
  case 3:
    if(currentFloor == 1) returnValueDegrees = map(sensorData, 1930, 550, 150, 255);
    if(currentFloor == 2) returnValueDegrees = map(sensorData, 1240, 550, 150, 255);
    if(currentFloor == 3) return;
    break;
  }

  //return sin(returnValueDegrees * PI/180) * maxVoltage;
  return returnValueDegrees;
}

