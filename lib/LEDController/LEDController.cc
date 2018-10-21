#include "LEDController.h"

void LEDController::init() {
  leds = new CRGB[NUM_LEDS];

  FastLED.addLeds<LED_TYPE, LED_DATA, CLR_ORDR>(leds, NUM_LEDS)
         .setCorrection(TypicalLEDStrip);
}

void LEDController::setState(LEDStyle state) {
  ledState = state;
}

void LEDController::setBrightness(int brightness) {
  FastLED.setBrightness(brightness);
}

void LEDController::update() {
  // do Something
}
