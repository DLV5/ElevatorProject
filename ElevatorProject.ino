#include "UltraSonicSensor.h"
#include "Streaming.h"
UltraSonicSensor sensor1(true);

void setup() {
  Serial.begin(9600);
}

void loop() {
    sensor1.getPulses();
}
