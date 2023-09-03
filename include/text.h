#include <Arduino.h>
#include "def.h"

uint8_t convertCharacter(uint8_t character);
int getTextWidth(const uint8_t font[], const char *text);
// void scrollText(uint8_t var[PIXELS_X][PIXELS_Y][COLORS], uint8_t font[], const char *text, uint8_t row, uint8_t spaces, int scrollDelay);
void setText(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], const uint8_t font[], const char *text, uint8_t x, uint8_t y, uint16_t scrollDelay, bool inverted, bool refresh);
