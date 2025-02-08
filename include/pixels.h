#ifndef PIXELS_H
#define PIXELS_H

#include "def.h"

void setPixel(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], int8_t x, int8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh = false);
void clearPixel(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, bool refresh = false);
void setPixels(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], uint8_t r, uint8_t g, uint8_t b, bool refresh = false);
void clearPixels(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], bool refresh = false);
void setRect(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b, bool refresh = false);
void updateDisplay(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS]);

#endif // PIXELS_H