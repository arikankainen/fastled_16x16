#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 6

#define PIXELS_X 16
#define PIXELS_Y 16

uint8_t matrix[PIXELS_X][PIXELS_Y];

CRGB leds[NUM_LEDS];

void updateDisplay(uint8_t var[PIXELS_X][PIXELS_Y]);
void setPixel(uint8_t var[PIXELS_X][PIXELS_Y], uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh);
void setPixels(uint8_t var[PIXELS_X][PIXELS_Y], uint8_t r, uint8_t g, uint8_t b, bool refresh);
void clearPixels(uint8_t var[PIXELS_X][PIXELS_Y], bool refresh);

void setup() {
    // Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(1);

    for (uint8_t x = 0; x < 6; x++) {
        for (uint8_t y = 0; y < 6; y++) {
            setPixel(matrix, x, y, 255, 50, 255, false);
        }
    }

    updateDisplay(matrix);
}

void loop() {
}

void setPixel(uint8_t var[PIXELS_X][PIXELS_Y], uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh) {
    if (x < PIXELS_X && y < PIXELS_Y) {
        var[x][y] = 1;    // todo: set colors
    }

    if (refresh) updateDisplay(var);
}

void updateDisplay(uint8_t var[PIXELS_X][PIXELS_Y]) {
    for (uint8_t y = 0; y < PIXELS_Y; y++) {
        for (uint8_t x = 0; x < PIXELS_X; x++) {
            uint8_t col = (y % 2 == 0 ? PIXELS_X - (x + 1) : x);
            uint8_t row = y;
            uint8_t led = row * PIXELS_X + col;
            uint8_t on = var[x][y] == 1 ? 255 : 0;    // todo: rgb colors

            leds[led].setRGB(on, on, on);
        }
    }

    FastLED.show();
}

void setPixels(uint8_t var[PIXELS_X][PIXELS_Y], uint8_t r, uint8_t g, uint8_t b, bool refresh) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            var[x][y] = 1;
        }
    }

    if (refresh) updateDisplay(var);
}

void clearPixels(uint8_t var[PIXELS_X][PIXELS_Y], bool refresh) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            var[x][y] = 0;
        }
    }

    if (refresh) updateDisplay(var);
}