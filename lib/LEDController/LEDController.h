
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

  void setBrightness(int brightness);

  void update();
};
