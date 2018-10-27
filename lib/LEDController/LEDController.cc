#include "LEDController.h"

void LEDController::init() {
  leds = new CRGB[NUM_LEDS];

  FastLED.addLeds<LED_TYPE, LED_DATA, CLR_ORDR>(leds, NUM_LEDS)
         .setCorrection(TypicalLEDStrip);
}

void LEDController::incrementBrightness() {
  if (currentBrightness == 0) {
    currentBrightness = 2;
  } else {
    currentBrightness = currentBrightness * 2 > MAX_BRIGHTNESS ? 0 : currentBrightness * 2;
  }

  setBrightness(currentBrightness);
}

void LEDController::decrementBrightness() {
  if (currentBrightness == 2) {
    currentBrightness = 0;
  } else {
    currentBrightness = currentBrightness == 0 ? currentBrightness : currentBrightness / 2;
  }

  setBrightness(currentBrightness);
}

void LEDController::cycleStyle() {
  currentStyle = static_cast<LEDStyle>((currentStyle + 1) % (LEDStyle::CYCLE + 1));
}

void LEDController::setState(LEDStyle state) {
  currentStyle = state;
}

void LEDController::setBrightness(int brightness) {
  if (brightness <= MAX_BRIGHTNESS) {
    FastLED.setBrightness(brightness);
  }
}

void LEDController::update() {
  // do Something
}
