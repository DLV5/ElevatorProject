#pragma once

#include <Arduino.h>

class UltraSonicSensor{
  private:
  byte echoPin = 0b10;
  uint8_t echoPinDigit = 10;
  bool isDebugModeActive;
  uint16_t calculatePulses();
  void displayDistanceAndPulses(uint16_t pulses);
  public:
  UltraSonicSensor() : isDebugModeActive(false) {}
  UltraSonicSensor(bool mode) : isDebugModeActive(mode) {}
  uint16_t getPulses();
};