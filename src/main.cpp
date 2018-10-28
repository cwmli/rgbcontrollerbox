#include <Arduino.h>
#include <FastLED.h>

#include "BtnState.h"
#include "LEDController.h"

#define AUX_BTN 2

LEDController controller;
BtnState pin2(AUX_BTN);

void setup() {
    // Analog input setup (these are RESERVED)
    // P5, use analogRead(0)
    // P4, use analogRead(2)
    // P3, use analogRead(3)

    // Setup LEDController
    controller.init();

    // Setup aux button input
    pinMode(AUX_BTN, INPUT);

    // Setup PIN0 is our LED switch
    //pinMode(0, OUTPUT);
}

void loop() {
    int pin2State = pin2.get();

    if (pin2State == S_PRESS) {
        controller.incrementBrightness();
    } else if (pin2State == L_PRESS || pin2State == XL_PRESS) {
        controller.cycleStyle();
    } 
}
