#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Music.h"
#include "Elevator.h"
#include <EEPROM.h>
#include <avr/wdt.h>

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
  WDTCSR |= 0b00011000;
  WDTCSR = 0b01101001;



  Serial.begin(9600);

  data.motor = motor;
  data.sensor = sensor;
  data.music = music;
  data.inputHandler = inputHandler;

  data.currentFloor = EEPROM.read(0);

  elevator.data = data;

  Serial << "Current floor is: " << data.currentFloor << endl;

  //elevator.setTargetFloor(3);

}

void loop() {
  elevator.data.music.update();



  if(!debounce) {
    if(!digitalRead(A3)) elevator.setTargetFloor(1);
    if(!digitalRead(A4)) elevator.setTargetFloor(2);
    if(!digitalRead(A5)) elevator.setTargetFloor(3);
  }
  
  if(!elevator.data.music.isMusicPlaying){
    if(elevator.data.targetFloors[0] != 0){
      elevator.moveToTheFloor();
    } else {
      elevator.data.music.playSong();
    }
  } else {
    return;
  }

  if(millis() % 50 == 0) {
    elevator.checkIfTheFloorReached();
  }

  if(debounce) debounceDelay--;
  if(debounceDelay == 0) {
    debounceDelay = 50;
    debounce = false;
  }

  wdt_reset();
}
