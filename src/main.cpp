#include <Arduino.h>
#include <FastLED.h>

#define NUM_LEDS 256
#define DATA_PIN 6

#define PIXELS_X 16
#define PIXELS_Y 16
#define COLORS 3
#define R 0
#define G 1
#define B 2

uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS];
CRGB leds[NUM_LEDS];

void setPixel(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh);
void updateDisplay(uint8_t var[PIXELS_X][PIXELS_Y][COLORS]);
void setPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t r, uint8_t g, uint8_t b, bool refresh);
void clearPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], bool refresh);

void setup() {
    // Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(1);

    // for (uint8_t x = 0; x < 6; x++) {
    //     for (uint8_t y = 0; y < 6; y++) {
    //         setPixel(matrix, x, y, 255, 50, 255, false);
    //     }
    // }

    // setPixel(matrix, 13, 15, 0, 0, 255, false);
    // setPixel(matrix, 14, 15, 0, 255, 0, false);
    // setPixel(matrix, 15, 15, 255, 0, 0, false);

    // updateDisplay(matrix);

    // setPixels(matrix, 255, 255, 0, true);
}

void loop() {
    // setPixels(matrix, 255, 255, 0, true);
    // delay(1000);
    // clearPixels(matrix, true);
    // delay(1000);
}

void setPixel(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh) {
    if (x < PIXELS_X && y < PIXELS_Y) {
        var[x][y][R] = r;
        var[x][y][G] = g;
        var[x][y][B] = b;
    }

    if (refresh) updateDisplay(var);
}

void updateDisplay(uint8_t var[PIXELS_X][PIXELS_Y][COLORS]) {
    for (uint8_t y = 0; y < PIXELS_Y; y++) {
        for (uint8_t x = 0; x < PIXELS_X; x++) {
            uint8_t col = (y % 2 == 0 ? PIXELS_X - (x + 1) : x);
            uint8_t row = y;
            uint8_t led = row * PIXELS_X + col;

            leds[led].setRGB(var[x][y][R], var[x][y][G], var[x][y][B]);
        }
    }

    FastLED.show();
}

void setPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t r, uint8_t g, uint8_t b, bool refresh) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            var[x][y][R] = r;
            var[x][y][G] = g;
            var[x][y][B] = b;
        }
    }

    if (refresh) updateDisplay(var);
}

void clearPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], bool refresh) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            var[x][y][R] = 0;
            var[x][y][G] = 0;
            var[x][y][B] = 0;
        }
    }

    if (refresh) updateDisplay(var);
}