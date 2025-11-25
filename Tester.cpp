#include "Arduino.h"

#include "Tester.h"
#include "Streaming.h"

Tester::Tester(){
  Serial.begin(9600);
}

template<typename Type>
static bool Tester::compareEqual(const Type &a, const Type &b){
  Serial << a << " == " << b << ": " << (a == b) << endl;
  return a == b;
}

template bool Tester::compareEqual<int>(const int&, const int&);


void Tester::doUltrasonicSensorTests(){
   int minimalPulseValue = 233;
   int maximumPulseValue = 2076;
   
   //Include when we have sensor class
   //UltrasonicSensor sensor;

  //  if(minimalPulseValue > sensor.GetRawData()){
  //   Serial << "ERROR: Ultrasonic value is too small!!" << endl;
  //  }

  // if(maximumPulseValue < sensor.GetRawData()){
  //   Serial << "ERROR: Ultrasonic value is too big!!" << endl;
  //   }

}