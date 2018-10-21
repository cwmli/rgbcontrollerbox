#include "BtnState.h"
#include "Timings.h"

int BtnState::get() {
  int currentPinState = digitalRead(pin);

  if (currentPinState != lastPinState) {
    debounceStartTime = millis();
  }

  if ((millis() - debounceStartTime) > DB_TIME) {

    if (currentPinState == HIGH) {
      initialPressTime = initialPressTime == 0 ? millis() : initialPressTime;
      pressedTime = millis() - initialPressTime;
    }
    
    if (lastPinState == HIGH && currentPinState == LOW) {
      // released
      initialPressTime = 0;
      pressedTime = 0;

      if (pressedTime < S_PRESS_TIME)
        return N_PRESS;

      if (pressedTime > S_PRESS_TIME && pressedTime < L_PRESS_TIME) {
        return S_PRESS;
      } else if (pressedTime > L_PRESS_TIME && pressedTime < XL_PRESS_TIME) {
        return L_PRESS;
      } else if (pressedTime > XL_PRESS_TIME) {
        return XL_PRESS;
      }
    } else {
      return N_PRESS;
    }

    lastPinState = currentPinState;
  }
}
