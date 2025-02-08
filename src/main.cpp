#include "def.h"
#include "colors.h"
#include "pixels.h"
#include "font-big.h"
#include "font-small.h"
#include "text.h"
#include "frames.h"

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

void setFrame(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], uint8_t frame[16][16], bool mirrored = false, uint16_t rotation = 0, bool refresh = false) {
    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            uint8_t item = frame[y][x];
            
            if (item > 0) {
                auto [r, g, b] = getRgbValues(item);
                if (mirrored) {
                    if (rotation == 90) setPixel(matrix, 15 - y, 15 - x, r, g, b, false);
                    else if (rotation == 180) setPixel(matrix, x, 15 - y, r, g, b, false);
                    else if (rotation == 270) setPixel(matrix, y, x, r, g, b, false);
                    else setPixel(matrix, 15 - x, y, r, g, b, false);
                }
                else {
                    if (rotation == 90) setPixel(matrix, 15 - y, x, r, g, b, false);
                    else if (rotation == 180) setPixel(matrix, 15 - x, 15 - y, r, g, b, false);
                    else if (rotation == 270) setPixel(matrix, y, 15 - x, r, g, b, false);
                    else setPixel(matrix, x, y, r, g, b, false);
                }
            }
        }
    }

    if (refresh) updateDisplay(matrix);
}

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(3); // NOTE! Keep brightness under 10 so that the LEDs don't draw too much current
    Serial.begin(9600);
    clearPixels(matrix, true);
}

void loop() {
    // clearPixels(matrix);
    // setFrame(matrix, frameStand, false, 0, true);
    // delay(1000);

    // clearPixels(matrix);
    // setFrame(matrix, frameStand, true, 0, true);
    // delay(1000);

    clearPixels(matrix);
    setFrame(matrix, frameStand, false, 0, true);
    delay(1000);

    clearPixels(matrix);
    setFrame(matrix, frameStand, true, 270, true);
    delay(1000);

    // for (uint8_t i = 0; i < 10; i++) {
    //     drawFrame(frameRun1, true);
    //     drawFrame(frameRun2, true);
    //     drawFrame(frameRun3, true);
    //     drawFrame(frameRun2, true);
    // }

    // drawMirroredFrame(frameTurn, true, 500);
    // drawMirroredFrame(frameStand, true, 3000);
    
    // for (uint8_t i = 0; i < 10; i++) {
    //     drawMirroredFrame(frameRun1, true);
    //     drawMirroredFrame(frameRun2, true);
    //     drawMirroredFrame(frameRun3, true);
    //     drawMirroredFrame(frameRun2, true);
    // }

    // drawFrame(frameTurn, true, 500);
    // drawFrame(frameStand, true, 3000);
}
