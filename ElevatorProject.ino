#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "Music.h"

Music music;
Tester tester;
InputHandler InputHandler;
MotorController motorController;

bool debounce = false;
int debounceDelay = 50;

  Serial.begin(9600);
  //tester.compareEqual<int>(1, 2);
  Serial << "Starting the motor" << endl;
  motorController.toggleMotor();
  motorController.setRotationSpeed(150);
  //motorController.changeDirection();
  // Serial << "Changed direction" << endl;
  // delay(3000);
  //motorController.toggleMotor();
  //Serial << "Stopping the motor" << endl;

void setup() {
  Serial.begin(9600);
}

void loop() {
  if(millis() % 6000 == 5999) {
    if(!debounce){
      Serial << "turning off" << endl;
      motorController.toggleMotor();
      debounce = true;
    }
  }

  //music.playSong();
  if(debounce) debounceDelay--;
  if(debounceDelay == 0) {
    debounceDelay = 50;
    debounce = false;
  }
}
