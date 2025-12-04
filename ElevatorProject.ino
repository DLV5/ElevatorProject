#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Music.h"
#include "Elevator.h"
#include <EEPROM.h>

MotorController motor;
UltraSonicSensor sensor;
Music music;
Tester tester;
InputHandler inputHandler;

Elevator elevator;
ElevatorData data;

bool debounce = false;
int debounceDelay = 50;

void setup() {
  Serial.begin(9600);

  data.motor = motor;
  data.sensor = sensor;
  data.music = music;
  data.inputHandler = inputHandler;

  data.currentFloor = EEPROM.read(0);

  data.targetFloors[1] = 1;
  data.targetFloors[2] = 2;


  Serial << "Current floor is: " << data.currentFloor << endl;

  elevator.data = data;

  elevator.setTargetFloor(3);

}

void loop() {
  // if(millis() % 6000 == 5999) {
  //   if(!debounce){
  //     Serial << "turning off" << endl;
  //     motorController.toggleMotor();
  //     debounce = true;
  //   }
  // }

  // //music.playSong();
  // if(debounce) debounceDelay--;
  // if(debounceDelay == 0) {
  //   debounceDelay = 50;
  //   debounce = false;
  // }

  if(millis() % 100 == 0) {
    elevator.checkIfTheFloorReached();
  }
}
