#include "Tester.h"
#include "InputHandler.h"
#include "Streaming.h"

Tester tester;
InputHandler InputHandler;

void setup() {
  Serial.begin(9600);
  //tester.compareEqual<int>(1, 2);
}

void loop() {
  Serial << InputHandler.calculateVoltageBasedOnUltrasonicData(1100) << endl;
}
