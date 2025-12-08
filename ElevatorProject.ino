#include "InputHandler.h"
#include "MotorController.h"
#include "UltraSonicSensor.h"
#include "Music.h"
#include "Elevator.h"
#include <EEPROM.h>
#include <avr/wdt.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); 
MotorController motor;
UltraSonicSensor sensor;
Music music;
InputHandler inputHandler;

Elevator elevator;
ElevatorData data;

bool debounce = false;
int debounceDelay = 50;

int secondCounter = 0;

void setup() {
  WDTCSR |= 0b00011000;
  WDTCSR = 0b01101001;

  TCCR1A = 0;           // Init Timer1A
  TCCR1B = 0;           // Init Timer1B
  TCCR1B |= B00000100;  // Prescaler = 256
  OCR1A = 62500;        // Timer Compare1A Register
  TIMSK1 |= B00000010;  // Enable Timer COMPA Interrupt

  data.motor = motor;
  data.sensor = sensor;
  data.music = music;
  data.inputHandler = inputHandler;

  data.currentFloor = EEPROM.read(0);

  elevator.data = data;

  lcd.init();

  elevator.updateNumbersOnDisplay(lcd);
}

void loop() {
  elevator.data.music.update();

  if(!debounce) {
    if(!digitalRead(A1)) elevator.setTargetFloor(1);
    if(!digitalRead(A2)) elevator.setTargetFloor(2);
    if(!digitalRead(A3)) elevator.setTargetFloor(3);
  }
  
  if(!elevator.data.music.isMusicPlaying){
    if(elevator.data.targetFloors[0] != 0){
      elevator.moveToTheFloor();
      secondCounter = 0;
    } else {
      elevator.data.music.playSong();
    }
  } else {
      lcd.setCursor(0, 1);
      lcd.print("Seconds AFK: ");
      lcd.print(secondCounter);
      return;
  }

  if(millis() % 50 == 0) {
    elevator.checkIfTheFloorReached();
    elevator.updateNumbersOnDisplay(lcd);
  }

  if(debounce) debounceDelay--;
  if(debounceDelay == 0) {
    debounceDelay = 50;
    debounce = false;
  }

  wdt_reset();
}

ISR(WDT_vect){
  EEPROM.write(0, elevator.data.currentFloor);
}

ISR(TIMER1_COMPA_vect)
{
  OCR1A += 62500; // Advance The COMPA Register
  
  ++secondCounter;
}