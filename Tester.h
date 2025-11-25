#pragma once

#include "Arduino.h"

class Tester{
  private:
    bool testUltrasonicPins();
    bool testUltrasonicData();

  public:
    Tester();
    template<typename Type>
    static bool compareEqual(const Type &a, const Type &b);

    void doMotorControllerTests();
    void doElevatorTests();
    void doElevatorDataTests();
    void doUltrasonicSensorTests();
    void doInputHandlerTests();
    void doSevenSegmentMonitorTests();
};