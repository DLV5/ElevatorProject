#pragma once

#include "Arduino.h"
#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "Music.h"
#include "UltraSonicSensor.h"

struct ElevatorData{
  MotorController motor;
  UltraSonicSensor sensor;
  Music music;
  InputHandler inputHandler;

  //EEROM reading should be added later
  uint8_t currentFloor;
  uint8_t targetFloors[3];
  uint8_t targetFloorsIndexes = 0;
  uint8_t errorMargin = 50;

  bool isMoving = false;
};

class Elevator {
  private:
  void updateNumbersOnDisplay();
  void stop();

  public:
  ElevatorData data;
  void moveToTheFloor();
  bool pulsesToFloor(uint16_t pulses);
  void setTargetFloor(int floorNumber);
  void checkIfTheFloorReached();
};