#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 42
#define LED_DATA 1
#define LED_TYPE WS2811
#define CLR_ORDR GRB


CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<LED_TYPE, LED_DATA, CLR_ORDR>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
    FastLED.setBrightness(16);
    // Analog input setup (these are RESERVED)
    // P5, use analogRead(0)
    // P4, use analogRead(2)
    // P3, use analogRead(3)
    // Setup aux button input
    pinMode(2, INPUT);
}

void loop() {
    // put your main code here, to run repeatedly:
}
