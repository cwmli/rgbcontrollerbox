#include "BtnState.h"
#include "Timings.h"

int BtnState::get() {
  int currentPinState = digitalRead(pin);

  if (currentPinState != lastPinState) {
    debounceStartTime = millis();
  }

  if ((millis() - debounceStartTime) > DB_TIME) {
    
  }
}
