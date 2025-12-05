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

//int stopDebounce = 0;

void setup() {

  Serial.begin(9600);

  data.motor = motor;
  data.sensor = sensor;
  data.music = music;
  data.inputHandler = inputHandler;

  data.currentFloor = 1;//EEPROM.read(0);
  //data.targetFloors[0] = 2;

  elevator.data = data;

  // Serial << "First floor when pulses are 950: " << elevator.pulsesToFloor(950) << endl;

  // elevator.data.targetFloors[0] = 3;

  // Serial << "First floor when pulses are 450: " << elevator.pulsesToFloor(450) << endl;

  // elevator.data.currentFloor = 2;
  // elevator.data.targetFloors[0] = 1;

  // Serial << "Second floor when pulses are 1600: " << elevator.pulsesToFloor(1600) << endl;

  // elevator.data.targetFloors[0] = 3;

  // Serial << "Second floor when pulses are 450: " << elevator.pulsesToFloor(450) << endl;

  // elevator.data.currentFloor = 3;
  // elevator.data.targetFloors[0] = 2;

  // Serial << "Third floor when pulses are 1000: " << elevator.pulsesToFloor(1000) << endl;

  // elevator.data.targetFloors[0] = 1;

  // Serial << "Third floor when pulses are 1600: " << elevator.pulsesToFloor(1600) << endl;
  // // data.targetFloors[1] = 1;
  // data.targetFloors[2] = 2;


  Serial << "Current floor is: " << data.currentFloor << endl;

  //elevator.setTargetFloor(3);

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

  if(!debounce) {
    // Serial << "Pin A3 value: " << digitalRead(A3) << endl;
    // Serial << "Pin A4 value: " << digitalRead(A4) << endl;
    // Serial << "Pin A5 value: " << digitalRead(A5) << endl;
    // Serial << endl << endl;
    if(!digitalRead(A3)) elevator.setTargetFloor(1);
    if(!digitalRead(A4)) elevator.setTargetFloor(2);
    if(!digitalRead(A5)) elevator.setTargetFloor(3);
  }

  if(millis() % 50 == 0) {
    elevator.checkIfTheFloorReached();
  }

  //if(stopDebounce != 0) --stopDebounce;
  if(debounce) debounceDelay--;
  if(debounceDelay == 0) {
    debounceDelay = 50;
    debounce = false;
  }
}
