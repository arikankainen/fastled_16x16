#ifndef COLORS_H
#define COLORS_H

#include <Arduino.h>

struct ColorRGB {
    uint8_t r, g, b;
};

extern ColorRGB colorRed;
extern ColorRGB colorGreen;
extern ColorRGB colorYellow;
extern ColorRGB colorBlue;
extern ColorRGB colorBlack;
extern ColorRGB colorWhite;

ColorRGB getRgbValues(uint8_t color);

#endif // COLORS_H