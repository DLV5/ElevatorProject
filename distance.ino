#include "UltraSonicSensor.h"
UltraSonicSensor sensor1;

void setup() {
  DDRB = 0b10;
  Serial.begin(9600);
}

void loop() {
  int duration;
  float distance;
  duration = sensor1.getPulses();
  Serial.print("Pulses: ");
  Serial.println(duration);
  distance = (duration*0.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(500);
}
