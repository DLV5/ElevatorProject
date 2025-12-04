#include <Arduino.h>

class UltraSonicSensor{
  private:
  uint8_t echoPin = 10;
  bool isDebugModeActive;
  uint16_t calculatePulses();
  void displayDistanceAndPulses(uint16_t pulses);
  public:
  UltraSonicSensor() : isDebugModeActive(false) {}
  UltraSonicSensor(bool mode) : isDebugModeActive(mode) {}
  uint16_t getPulses();
};