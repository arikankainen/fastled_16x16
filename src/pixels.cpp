#include "def.h"
#include "pixels.h"
#include "colors.h"

void setPixel(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    int8_t x,
    int8_t y,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    bool refresh
) {
    if (x >= 0 && y >= 0 && x < PIXELS_X && y < PIXELS_Y) {
        matrix[x][y][R] = r;
        matrix[x][y][G] = g;
        matrix[x][y][B] = b;
    }

    if (refresh) updateDisplay(matrix);
}

void clearPixel(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    uint8_t x,
    uint8_t y,
    bool refresh
) {
    if (x < PIXELS_X && y < PIXELS_Y) {
        matrix[x][y][R] = 0;
        matrix[x][y][G] = 0;
        matrix[x][y][B] = 0;
    }

    if (refresh) updateDisplay(matrix);
}

void setPixels(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    uint8_t r,
    uint8_t g,
    uint8_t b,
    bool refresh
) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            matrix[x][y][R] = r;
            matrix[x][y][G] = g;
            matrix[x][y][B] = b;
        }
    }

    if (refresh) updateDisplay(matrix);
}

void clearPixels(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    bool refresh
) {
    for (uint8_t x = 0; x < PIXELS_X; x++) {
        for (uint8_t y = 0; y < PIXELS_Y; y++) {
            matrix[x][y][R] = 0;
            matrix[x][y][G] = 0;
            matrix[x][y][B] = 0;
        }
    }

    if (refresh) updateDisplay(matrix);
}

void setRect(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    uint8_t x,
    uint8_t y,
    uint8_t x2,
    uint8_t y2,
    uint8_t r,
    uint8_t g,
    uint8_t b,
    bool refresh
) {
    for (uint8_t yy = y; yy <= y2; yy++) {
        for (uint8_t xx = x; xx <= x2; xx++) {
            setPixel(matrix, xx, yy, r, g, b, false);
        }
    }

    if (refresh) updateDisplay(matrix);
}

void setFrame(
    uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS],
    uint8_t frame[16][16],
    bool mirrored,
    uint16_t rotation,
    int8_t offsetX,
    int8_t offsetY,
    bool refresh
) {
    for (uint8_t y = 0; y < 16; y++) {
        for (uint8_t x = 0; x < 16; x++) {
            if (frame[y][x] == 0) continue;
            auto [r, g, b] = getRgbValues(frame[y][x]);

            if (mirrored) {
                switch (rotation) {
                    case 0:
                        setPixel(matrix, 15 - x + offsetX, y + offsetY, r, g, b, false);
                        break;
                    case 90:
                        setPixel(matrix, 15 - y + offsetX, 15 - x + offsetY, r, g, b, false);
                        break;
                    case 180:
                        setPixel(matrix, x + offsetX, 15 - y + offsetY, r, g, b, false);
                        break;
                    case 270:
                        setPixel(matrix, y + offsetX, x + offsetY, r, g, b, false);
                        break;
                }
            }
            else {
                switch (rotation) {
                    case 0:
                        setPixel(matrix, x + offsetX, y + offsetY, r, g, b, false);
                        break;
                    case 90:
                        setPixel(matrix, 15 - y + offsetX, x + offsetY, r, g, b, false);
                        break;
                    case 180:
                        setPixel(matrix, 15 - x + offsetX, 15 - y + offsetY, r, g, b, false);
                        break;
                    case 270:
                        setPixel(matrix, y + offsetX, 15 - x + offsetY, r, g, b, false);
                        break;
                }
            }
        }
    }

    if (refresh) updateDisplay(matrix);
}

void updateDisplay(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS]) {
    for (uint8_t y = 0; y < PIXELS_Y; y++) {
        for (uint8_t x = 0; x < PIXELS_X; x++) {
            // odd rows of led matrix run backwards:
            // leds[0] =  right corner of the first row  (x: 15, y: 0)
            // leds[15] = left corner of the first row   (x: 0, y: 0)
            // leds[16] = left corder of the second row  (x: 0, y: 1)
            // leds[31] = right corner of the second row (x: 15, y: 1)

            uint8_t col = (y % 2 == 0 ? PIXELS_X - (x + 1) : x);
            uint8_t row = y;
            uint8_t led = row * PIXELS_X + col;

            leds[led].setRGB(matrix[x][y][R], matrix[x][y][G], matrix[x][y][B]);
        }
    }

    FastLED.show();
}
