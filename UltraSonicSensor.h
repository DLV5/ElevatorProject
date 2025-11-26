#include <Arduino.h>

class UltraSonicSensor{
  private:
  uint8_t echoPin = 10;
  uint16_t calculatePulses();
  public:
  uint16_t getPulses();
};