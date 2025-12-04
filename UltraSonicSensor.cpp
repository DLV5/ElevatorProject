#include "UltraSonicSensor.h"
#include "Streaming.h"
uint16_t UltraSonicSensor::calculatePulses() {
  PORTB = 0b0;
  delayMicroseconds(2);
  PORTB = 0b10;
  delayMicroseconds(10);
  PORTB = 0b0;

  uint16_t valueToReturn = pulseIn(echoPin, 1);

  if(isDebugModeActive) displayDistanceAndPulses(valueToReturn);

  return valueToReturn;
}

void UltraSonicSensor::displayDistanceAndPulses(uint16_t pulses){
  //if(millis() % 500 != 0) return;

  float distance;
  Serial << "Pulses: " << pulses << endl;
  distance = (pulses*0.0343)/2;
  Serial << "Distance: " << distance << endl;
}

uint16_t UltraSonicSensor::getPulses() {
  return (calculatePulses());
}