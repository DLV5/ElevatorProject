#include "HardwareSerial.h"
#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Elevator.h"
#include "Streaming.h"
#include <EEPROM.h>

void Elevator::updateNumbersOnDisplay(LiquidCrystal_I2C lcd){
  lcd.setCursor(0,0);
  lcd.print("Curren floor: ");
  lcd.print(data.currentFloor);
}

void Elevator::moveToTheFloor(){
  if(data.isMoving) return;

  uint8_t voltage = data.inputHandler.calculateVoltageBasedOnUltrasonicData(
    data.sensor.getPulses(), 
    data.targetFloors[0], 
    data.currentFloor);


  Serial << "Going to the floor: " << data.targetFloors[0] << " from the floor " << data.currentFloor << endl;
  
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

bool Elevator::pulsesToFloor(uint16_t pulses){

  //Serial << data.currentFloor << " " << data.targetFloors[0] << " " << pulses << endl;

  switch(data.currentFloor){
    case 1:
      if(data.targetFloors[0] == 2){
        return pulses < 970;
      }
      else
       return pulses < 460;

      break;
    case 2:
      if(data.targetFloors[0] == 1){
        return pulses > 1530;
      }
      else
       return pulses < 460; 

      break;
    case 3:
      if(data.targetFloors[0] == 2){
        return pulses > 970;
      }
      else
       return pulses > 1530;

      break;
  }
}

void Elevator::setTargetFloor(int floorNumber){
  if(data.targetFloorsIndexes > 2) return;

  bool isUniqueFloor = true;

  if(data.currentFloor == floorNumber) return;

  for(int i = 0; i < 2; i++){
    if(data.targetFloors[i] == floorNumber){
      isUniqueFloor = false;
    }
  }

  if(!isUniqueFloor) return;

  Serial << "Succesfully added number: " << floorNumber << " to the list" << endl;
  data.targetFloors[data.targetFloorsIndexes] = floorNumber;
  ++data.targetFloorsIndexes;

  //Serial << "Is moving currently " << data.isMoving << endl;
  if(!data.isMoving){
    data.music.stopAndReset();
    moveToTheFloor();
  }
}

void Elevator::checkIfTheFloorReached(){
  uint16_t pulses = data.sensor.getPulses();

  if(data.isMoving && pulsesToFloor(pulses)){
    stop();
    data.currentFloor = data.targetFloors[0];
    Serial << "Current floor is: " << data.currentFloor << endl;
    EEPROM.write(0, data.currentFloor);

    --data.targetFloorsIndexes;

    data.targetFloors[0] = data.targetFloors[1];
    data.targetFloors[1] = data.targetFloors[2];
    data.targetFloors[2] = 0;

    data.music.playSong();

    // if(data.targetFloors[0] != 0)
    //   moveToTheFloor();
    //Serial << data.targetFloorsIndexes << " Floor index" << endl;
    //Serial << data.currentFloor << " current floor" << endl;
  }
}