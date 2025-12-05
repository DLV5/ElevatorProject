#pragma once

#include "Arduino.h"
#include "pitches.h"

class Music{
private:
  uint32_t maintime = 1000;
  int melody[11] = {
  NOTE_G5, NOTE_B5, NOTE_FS5, NOTE_F5, NOTE_G5,
  NOTE_E5, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_CS5,
  NOTE_D5 //REST, NOTE_E5, REST
};
  int durations[11] = {
  1, 2, 2, 1, 2, 2, 2, 2, 2, 2, 2 //1, 2, 1
};
  int currentNote = 0;
  unsigned long noteStart = 0;

public:
  Music();
  bool isMusicPlaying = true;
  void playSong();
  void update();
  void stopAndReset();
};