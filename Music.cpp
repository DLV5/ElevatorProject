#include "HardwareSerial.h"
#include "Arduino.h"
#include "Music.h"
#include "Streaming.h"

#define BUZZER_PIN 8

Music::Music(){
    pinMode(BUZZER_PIN, OUTPUT);
}

void Music::playSong(){
  isMusicPlaying = true;
}

void Music::update(){
  if(!isMusicPlaying) return;

  if(millis() >= (maintime / durations[currentNote] * 1.3) + noteStart ){
    if(currentNote > 10) {
        stopAndReset();
        return;
      }

    currentNote++;

    tone(BUZZER_PIN, melody[currentNote], maintime / durations[currentNote]);
    noteStart = millis();
  }
}

void Music::stopAndReset(){
   currentNote = 0;
   noTone(BUZZER_PIN);
   isMusicPlaying = false;
}
