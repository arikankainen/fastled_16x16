#include "def.h"
#include "pixels.h"

uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS];
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(1);

    // setPixel(matrix, 13, 15, 0, 0, 255, false);
    // setPixel(matrix, 14, 15, 0, 255, 0, false);
    // setPixel(matrix, 15, 15, 255, 0, 0, false);

    // updateDisplay(matrix);

    // setPixels(matrix, 255, 0, 255, true);
    setRect(matrix, 5, 5, 9, 9, 255, 255, 0, true);
}

void loop() {
    // for (uint8_t i = 0; i < 256; i++) {
    //     FastLED.showColor(CHSV(i, 255, 255));
    //     // delay(10);
    // }

    // setPixels(matrix, 255, 255, 0, true);
    // delay(1000);
    // clearPixels(matrix, true);
    // delay(1000);
}
