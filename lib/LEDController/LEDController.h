
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
  LEDStyle ledState;

  LEDController() {
    FastLED.setBrightness(DEFAULT_BRIGHTNESS);
    ledState = LEDStyle::SOLID;
  }

  ~LEDController() {
    delete leds;
  }

public:

  void init();

  void setState(LEDStyle state);

  void setBrightness(int brightness);

  void update();
};
