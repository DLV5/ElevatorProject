#include "Tester.h"
#include "Streaming.h"
Tester tester;

void setup() {
  Serial.begin(9600);

  tester.compareEqual<int>(1, 2);
}

void loop() {
  // put your main code here, to run repeatedly:
}
