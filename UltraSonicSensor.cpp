#include "UltraSonicSensor.h"
#include "Streaming.h"

uint16_t UltraSonicSensor::calculatePulses() {
  PORTB ^= echoPin;
  delayMicroseconds(10);
  PORTB ^= echoPin;

  uint16_t valueToReturn = pulseIn(echoPinDigit, 1);

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