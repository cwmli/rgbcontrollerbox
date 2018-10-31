#include <Arduino.h>

#include "BtnState.h"
#include "LEDController.h"

#define AUX_BTN 0

LEDController controller;
BtnState pin2(AUX_BTN);

void setup() {
    // Analog input setup (these are RESERVED)
    // P2, use analogRead(1)
    // P4, use analogRead(2)
    // P3, use analogRead(3)
    pinMode(2, INPUT);
    pinMode(4, INPUT);
    pinMode(3, INPUT);

    // Setup LEDController
    controller.init();

    pinMode(1, OUTPUT);
    pinMode(AUX_BTN, INPUT);
}

void loop() {
    uint8_t pin2State = pin2.get();
    uint8_t ctrlState = controller.getState();

    if (pin2State == S_PRESS) {
        controller.incrementBrightness();
    } else if (pin2State == L_PRESS) {
        controller.incrementSpeed();
    } else if (pin2State == XL_PRESS) {
        controller.cycleStyle();
    }

    if (ctrlState != 2) {
        // normalize rgb values
        int16_t r = analogRead(3);
        int16_t g = analogRead(2);
        int16_t b = analogRead(1);
        r = r * 0.249;
        g = g * 0.249;
        b = b * 0.249;

        controller.setSolidColor(r, g, b);
    }
    controller.update();
}
