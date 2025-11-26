#include "InputHandler.h"

uint8_t* InputHandler::getPins(){
  return _elevatorFloorButtonPins;
}

uint8_t InputHandler::calculateVoltageBasedOnUltrasonicData(uint16_t data){
  // 2070 - max pulse value -> about 35cm bottom position
  uint8_t maxVoltage = 255;
  uint8_t returnValueDegrees;

  // from first floor to the second
  if(data > 874){
    returnValueDegrees = map(data, 1457, 875, 0, 180);
  } 
  // from second floor to the third
  else {
    returnValueDegrees = map(data, 874, 0, 0, 180);
  }

  return sin(returnValueDegrees * PI/180) * maxVoltage;
}

