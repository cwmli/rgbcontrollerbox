
#include <FastLED.h>

#define NUM_LEDS           42
#define LED_DATA           1
#define LED_TYPE           WS2811
#define CLR_ORDR           GRB

#define DEFAULT_BRIGHTNESS 16
#define MAX_BRIGHTNESS     64 
#define SDL_TRANSITION     36

class CRGB;

enum LEDStyle {
  SOLID,
  BREATHING
};

class LEDController {
  CRGB leds[NUM_LEDS];
  LEDStyle currentStyle;
  uint8_t currentBrightness;

  CRGB oldColor;
  CRGB targetColor;

  // breatheTimer
  unsigned long startBreatheTimer;

public:
  LEDController() {
    currentBrightness = DEFAULT_BRIGHTNESS;
    FastLED.setBrightness(currentBrightness);
    currentStyle = LEDStyle::SOLID;
    oldColor = targetColor = CRGB::Red;
  }

  void init();

  void incrementBrightness();

  void decrementBrightness();

  void cycleStyle();

  void setState(LEDStyle state);

  void setBrightness(uint8_t brightness);

  void setSolidColor(uint8_t r, uint8_t g, uint8_t b);

  void update();

private:

  void solid(CRGB *old, CRGB *target, uint8_t transition);

  void breathe();
};
