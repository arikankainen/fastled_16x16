#include "def.h"
#include "pixels.h"
#include "font-big.h"
#include "font-small.h"
#include "text.h"
#include "frames.h"

uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS];
CRGB leds[NUM_LEDS];

struct ColorRGB {
    uint8_t r, g, b;
};

/*
    NOTE! Keep brightness level under 10 so that the LEDs don't draw too much current from Arduino's 5V pin!
    
    With brightness level 3, there are only 3 shades available (+ black)
    0-63: black
    64-127: darkest
    128-191: medium
    192-255: brightest
*/


uint8_t brightness = 3;

ColorRGB colorRed = { 128, 0, 0 };
ColorRGB colorGreen = { 64, 64, 0 };
ColorRGB colorYellow = { 192, 128, 0 };
ColorRGB colorBlue = { 64, 64, 128 };
ColorRGB colorBlack = { 0, 0, 0 };

ColorRGB getRgbValues(uint8_t color) {
    switch (color) {
        case 1: return colorRed;
        case 2: return colorGreen;
        case 3: return colorYellow;
        default: return colorBlack;
    }
}

void mirrorFrame(uint8_t frame[16][16]) {
    uint8_t mirroredFrame[16][16];

    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            mirroredFrame[y][x] = frame[y][15 - x];
        }
    }
}

void drawFrame(uint8_t frame[16][16], bool update, int displayTime = 100) {
    auto [r, g, b] = colorBlue;
    setPixels(matrix, r, g, b, false);

    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            uint8_t item = frame[y][x];
            
            if (item > 0) {
                auto [r, g, b] = getRgbValues(item);
                setPixel(matrix, x, y, r, g, b, false);
            }
        }
    }

    if (update) updateDisplay(matrix);
    if (delay > 0) delay(displayTime);
}

void drawMirroredFrame(uint8_t frame[16][16], bool update, int displayTime = 100) {
    auto [r, g, b] = colorBlue;
    setPixels(matrix, r, g, b, false);

    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            uint8_t item = frame[y][x];

            if (item > 0) {
                auto [r, g, b] = getRgbValues(item);
                setPixel(matrix, 15 - x, y, r, g, b, false);
            }
        }
    }

    if (update) updateDisplay(matrix);
    if (delay > 0) delay(displayTime);
}

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(brightness);
    Serial.begin(9600);
    setPixels(matrix, 0, 0, 0, true);
}

void loop() {
    for (uint8_t i = 0; i < 10; i++) {
        drawFrame(frameRun1, true);
        drawFrame(frameRun2, true);
        drawFrame(frameRun3, true);
        drawFrame(frameRun2, true);
    }

    drawMirroredFrame(frameTurn, true, 500);
    drawMirroredFrame(frameStand, true, 3000);
    
    for (uint8_t i = 0; i < 10; i++) {
        drawMirroredFrame(frameRun1, true);
        drawMirroredFrame(frameRun2, true);
        drawMirroredFrame(frameRun3, true);
        drawMirroredFrame(frameRun2, true);
    }

    drawFrame(frameTurn, true, 500);
    drawFrame(frameStand, true, 3000);
}
