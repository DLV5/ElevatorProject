#include "UltraSonicSensor.h"

uint16_t UltraSonicSensor::calculatePulses() {
  PORTB = 0b0;
  delayMicroseconds(2);
  PORTB = 0b10;
  delayMicroseconds(10);
  PORTB = 0b0;
  return pulseIn(echoPin, 1);
}

uint16_t UltraSonicSensor::getPulses() {
  return (calculatePulses());
}