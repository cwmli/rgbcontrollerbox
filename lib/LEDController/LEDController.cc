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
  if (currentStyle == LEDStyle::BREATHING) {
    startBreatheTimer = millis();
  }
}

void LEDController::setBrightness(uint8_t brightness) {
  if (brightness <= MAX_BRIGHTNESS) {
    FastLED.setBrightness(brightness);
  }
}

void LEDController::setSolidColor(uint8_t r, uint8_t g, uint8_t b) {
  oldColor = targetColor;
  targetColor.setRGB(r, g, b);
}

void LEDController::update() {
  switch(currentStyle) {
    case LEDStyle::SOLID:
      solid(&oldColor, &targetColor, SDL_TRANSITION);
      break;
    case LEDStyle::BREATHING:
      breathe();
      break;
    case LEDStyle::CYCLE:
      break;
  }

  FastLED.show();
}

void LEDController::solid(CRGB *old, CRGB *target, int transition) {
    nblend(*old, *target, transition);
    fill_solid(leds, NUM_LEDS, *old);
}

void LEDController::breathe() {
  solid(&oldColor, &targetColor, SDL_TRANSITION);
  // ( e ^ ( sin(x) ) - 1 / e ) * ( currentBrightness / ( e - 1 / e ) )
  FastLED.setBrightness(
    (exp(sin((millis() - startBreatheTimer)/2000.0*PI)) - 0.36787944) * (currentBrightness / 2.35040238));
}

void LEDController::cycle() {
  
}
