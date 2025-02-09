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
    // animRunRightWithFireball();
    // delay(1000);

    // animRunLeftWithFireball();
    // delay(1000);

    // animRunRightInPlaceAndTurnLeft();
    // animRunLeftInPlaceAndTurnRight();

    animRunRightAndJumpOverKoopa();
}
