#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Elevator.h"
#include "Streaming.h"
#include <EEPROM.h>

void Elevator::updateNumbersOnDisplay(){

}

void Elevator::moveToTheFloor(){
  if(data.isMoving) return;

  uint8_t voltage = data.inputHandler.calculateVoltageBasedOnUltrasonicData(
    data.sensor.getPulses(), 
    data.targetFloors[0], 
    data.currentFloor);


  Serial << "Going to the floor: " << data.targetFloors[0] << endl;
  data.motor.toggleMotor();
  if(data.currentFloor > data.targetFloors[0] && (data.motor.getDirection() == UP)){
    data.motor.changeDirection();
    data.motor.setRotationSpeed(voltage);
  }
  else if(data.currentFloor < data.targetFloors[0] && (data.motor.getDirection() == DOWN)){
    data.motor.setRotationSpeed(voltage);
    data.motor.changeDirection();
  } else {
    data.motor.setRotationSpeed(voltage);
  }

  data.isMoving = true;
}

void Elevator::stop(){
  data.motor.toggleMotor();
  data.motor.setRotationSpeed(0);
  data.isMoving = false;
}

void Elevator::setTargetFloor(int floorNumber){
  if(data.targetFloorsIndexes >= 2) return;

  data.targetFloors[data.targetFloorsIndexes] = floorNumber;
  ++data.targetFloorsIndexes;

  Serial << data.targetFloors[0] << "Target floor 0" << endl;
  Serial << data.targetFloors[1] << "Target floor 1" <<endl;
  Serial << data.targetFloors[2] << "Target floor 2" <<endl;

  moveToTheFloor();
}

void Elevator::checkIfTheFloorReached(){
  uint8_t voltage = data.inputHandler.calculateVoltageBasedOnUltrasonicData(
    data.sensor.getPulses(), 
    data.targetFloors[0], 
    data.currentFloor);

  // Serial << voltage << " voltage" << endl;
  // Serial << data.sensor.getPulses() << " pulses" << endl;
  //Serial << voltage << endl;
  if(data.isMoving && voltage < 45){
    stop();
    data.currentFloor = data.targetFloors[0];

    EEPROM.write(0, data.currentFloor == 0 ? 1 : data.currentFloor);

    --data.targetFloorsIndexes;

    data.targetFloors[0] = data.targetFloors[1];
    data.targetFloors[1] = data.targetFloors[2];
    data.targetFloors[2] = 0;

    if(data.targetFloors[0] != 0)
      moveToTheFloor();
    //Serial << data.targetFloorsIndexes << " Floor index" << endl;
    //Serial << data.currentFloor << " current floor" << endl;

  }
}