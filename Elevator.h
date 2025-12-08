#pragma once

#include "Arduino.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "Music.h"
#include "UltraSonicSensor.h"
#include <LiquidCrystal_I2C.h>

struct ElevatorData{
  MotorController motor;
  UltraSonicSensor sensor;
  Music music;
  InputHandler inputHandler;

  uint8_t currentFloor;
  uint8_t targetFloors[3];
  uint8_t targetFloorsIndexes = 0;
  uint8_t errorMargin = 50;

  bool isMoving = false;
};

class Elevator {
  private:
  void stop();

  public:
  ElevatorData data;
  void updateNumbersOnDisplay(LiquidCrystal_I2C lcd);
  void moveToTheFloor();
  bool pulsesToFloor(uint16_t pulses);
  void setTargetFloor(int floorNumber);
  void checkIfTheFloorReached();
};