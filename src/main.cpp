#include "def.h"
#include "demo.h"
#include "pixels.h"

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(3); // NOTE! Keep brightness under 10 so that the LEDs don't draw too much current
    Serial.begin(9600);
    clearPixels(matrix, true);
}

void loop() {
    animRunRightIn();
    animRunRightInPlace();
    animTurnLeft();
    delay(1000);
    animRunLeftInPlace();
    animRunLeftOut();

    animRunRightAndJumpOverKoopa();
    delay(500);

    animRunLeftWithFireball();

    animRunRightWithFireball();
    delay(500);

    animRunLeftAndJumpOverKoopa();
    delay(500);
}
