#ifndef BTNSTATE_H
#define BTNSTATE_H

#include <Arduino.h>

class BtnState {

  int pin;
  int lastPinState;

  unsigned long lastTime;
  unsigned long pressedTime;
  unsigned long debounceStartTime;

  public:
    BtnState(int pin) : pin(pin) {
      lastPinState = LOW;
      pressedTime = 0;
      debounceStartTime = 0;
    }

    int get();
};

#endif
