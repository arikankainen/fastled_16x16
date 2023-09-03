#include "def.h"
#include "pixels.h"
#include "font-big.h"
#include "font-small.h"
#include "text.h"

uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS];
CRGB leds[NUM_LEDS];

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(10);

    // setPixel(matrix, 13, 15, 0, 0, 255, false);
    // setPixel(matrix, 14, 15, 0, 255, 0, false);
    // setPixel(matrix, 15, 15, 255, 0, 0, false);

    // updateDisplay(matrix);

    // setPixels(matrix, 22, 22, 22, true);
    // uint8_t hourLength = getTextWidth(fontSmall, "10");
    // uint8_t minuteLength = getTextWidth(fontSmall, "05");
    // setText(matrix, fontSmall, "10", int((PIXELS_X - hourLength) / 2), 0, 0, false, true);
    // setText(matrix, fontSmall, "05", int((PIXELS_X - minuteLength) / 2), 7, 0, false, true);
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
