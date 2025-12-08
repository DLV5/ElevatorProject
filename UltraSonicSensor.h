#pragma once

#include <Arduino.h>

class UltraSonicSensor{
  private:
  byte echoPin = 0b10;
  uint8_t echoPinDigit = 10;
  uint16_t calculatePulses();
  void displayDistanceAndPulses(uint16_t pulses);
  public:
  uint16_t getPulses();
};