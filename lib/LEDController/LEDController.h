
#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H

#include <FastLED.h>

#define NUM_LEDS           42
#define LED_DATA           1
#define LED_TYPE           WS2811
#define CLR_ORDR           GRB

#define DEFAULT_BRIGHTNESS 16
#define MAX_BRIGHTNESS     64 
#define SDL_TRANSITION     36

class CRGB;

class LEDController {
  CRGB leds[NUM_LEDS];
  // LET 0 be SOLID
  //     1 be BREATHING
  //     2 be COLOR CYCLE
  uint8_t currentStyle;
  uint8_t currentBrightness;

  CRGB color;

  // breatheTimer, cycleTimer
  unsigned long styleTimer;
  uint8_t cycle;
  uint16_t speed;

public:
  LEDController() {
    currentBrightness = DEFAULT_BRIGHTNESS;
    currentStyle = 2;
    speed = 250;
  }

  void init();

  void incrementBrightness();

  void incrementSpeed();

  void cycleStyle();

  void setState(uint8_t state);

  uint8_t getState();

  void setBrightness(uint8_t brightness);

  void setSolidColor(uint8_t r, uint8_t g, uint8_t b);

  void update();

private:

  void breathe();

  void rainbow();

  CRGB wheel(byte pos);
};
#endif
