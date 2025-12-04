#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Music.h"
#include "Elevator.h"

MotorController motor;
UltraSonicSensor sensor(true);
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

  //tester.compareEqual<int>(1, 2);
  Serial << "Elevator move to floor 2" << endl;
  //motor.changeDirection();
  elevator.setTargetFloor(2);
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
    // if(!debounce){
    //   Serial << "turning off" << endl;
    //   motorController.toggleMotor();
    //   debounce = true;
    // }
    elevator.checkIfTheFloorReached();
  }
}
