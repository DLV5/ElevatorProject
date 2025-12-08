#include "UltraSonicSensor.h"

uint16_t UltraSonicSensor::calculatePulses() {
  PORTB ^= echoPin;
  delayMicroseconds(10);
  PORTB ^= echoPin;

  uint16_t valueToReturn = pulseIn(echoPinDigit, 1);

  return valueToReturn;
}

uint16_t UltraSonicSensor::getPulses() {
  return (calculatePulses());
}