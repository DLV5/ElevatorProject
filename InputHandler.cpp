#include "Arduino.h"
#include "Elevator.h"
#include "InputHandler.h"

InputHandler::InputHandler(){
  //when we subttract A0, we will get corresponding port number A0-A7
  DDRC &= ((0 << (_elevatorFloorButtonPins[0] - A0)) 
  |  (0 << (_elevatorFloorButtonPins[1] - A0)) 
  |  (0 << (_elevatorFloorButtonPins[2] - A0)));
  
  PORTC |= (1 << (_elevatorFloorButtonPins[0] - A0)) 
  |  (1 << (_elevatorFloorButtonPins[1] - A0)) 
  |  (1 << (_elevatorFloorButtonPins[2] - A0));
}

uint8_t* InputHandler::getPins(){
  return _elevatorFloorButtonPins;
}

uint8_t InputHandler::calculateVoltageBasedOnUltrasonicData(uint16_t sensorData, uint8_t targetFloor, uint8_t currentFloor){
  return 200;
}

