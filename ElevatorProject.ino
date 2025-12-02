#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"
#include "MotorController.h"
#include "Music.h"

Music music;
Tester tester;
InputHandler InputHandler;
MotorController motorController;

void setup() {
  Serial.begin(9600);
  //tester.compareEqual<int>(1, 2);
  Serial << "Starting the motor" << endl;
  motorController.toggleMotor();
  motorController.changeDirection();
  motorController.setRotationSpeed(150);
  // Serial << "Changed direction" << endl;
  // delay(3000);
  //motorController.toggleMotor();
  Serial << "Stopping the motor" << endl;

}

void loop() {
  //music.playSong();
}
