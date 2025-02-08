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

ColorRGB colorRed = { 181, 49, 32 };
ColorRGB colorGreen = { 107, 109, 0 };
ColorRGB colorYellow = { 234, 158, 34 };
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
    clearPixels(matrix, false);

    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            uint8_t item = frame[y][x];
            auto [r, g, b] = getRgbValues(item);
            setPixel(matrix, x, y, r, g, b, false);
        }
    }

    if (update) updateDisplay(matrix);
    if (delay > 0) delay(displayTime);
}

void drawMirroredFrame(uint8_t frame[16][16], bool update, int displayTime = 100) {
    clearPixels(matrix, false);

    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            uint8_t item = frame[y][x];
            auto [r, g, b] = getRgbValues(item);
            setPixel(matrix, 15 - x, y, r, g, b, false);
        }
    }

    if (update) updateDisplay(matrix);
    if (delay > 0) delay(displayTime);
}

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(5);
    Serial.begin(9600);
    setPixels(matrix, 0, 0, 0, true);

    // uint8_t hourLength = getTextWidth(fontSmall, "10");
    // uint8_t minuteLength = getTextWidth(fontSmall, "05");
    // setText(matrix, fontSmall, "10", int((PIXELS_X - hourLength) / 2), 0, 0, false, true);
    // setText(matrix, fontSmall, "05", int((PIXELS_X - minuteLength) / 2), 7, 0, false, true);
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
