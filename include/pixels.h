#include "def.h"

void setPixel(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b, bool refresh);
void clearPixel(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, bool refresh);
void setPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t r, uint8_t g, uint8_t b, bool refresh);
void clearPixels(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], bool refresh);
void setRect(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t x, uint8_t y, uint8_t x2, uint8_t y2, uint8_t r, uint8_t g, uint8_t b, bool refresh);
void updateDisplay(uint8_t var[PIXELS_X][PIXELS_Y][COLORS]);
