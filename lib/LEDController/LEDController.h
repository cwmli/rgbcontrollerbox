
#include <FastLED.h>
#include "Config.h"

class CRGB;

enum LEDStyle {
  SOLID,
  BREATHING,
  CYCLE
};

class LEDController {
  CRGB *leds;
  LEDStyle currentStyle;
  int currentBrightness;

  CRGB oldColor;
  CRGB targetColor;

  // breatheTimer
  unsigned long startBreatheTimer;

  LEDController() {
    currentBrightness = DEFAULT_BRIGHTNESS;
    FastLED.setBrightness(currentBrightness);
    currentStyle = LEDStyle::SOLID;
  }

  ~LEDController() {
    delete leds;
  }

public:

  void init();

  void incrementBrightness();

  void decrementBrightness();

  void cycleStyle();

  void setState(LEDStyle state);

  void setBrightness(uint8_t brightness);

  void setSolidColor(uint8_t r, uint8_t g, uint8_t b);

  void update();

private:

  void solid(CRGB *old, CRGB *target, int transition);

  void breathe();

  void cycle();
};
