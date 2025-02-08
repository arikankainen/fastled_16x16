#include "colors.h"

/*
    With brightness level 3, there are only 3 shades available (+ black)
    0-63: black
    64-127: darkest
    128-191: medium
    192-255: brightest
*/

ColorRGB colorRed = { 128, 0, 0 };
ColorRGB colorGreen = { 64, 64, 0 };
ColorRGB colorYellow = { 192, 128, 0 };
ColorRGB colorBlue = { 64, 64, 128 };
ColorRGB colorBlack = { 0, 0, 0 };
ColorRGB colorWhite = { 192, 192, 192 };

ColorRGB getRgbValues(uint8_t color) {
    switch (color) {
        case 1: return colorRed;
        case 2: return colorGreen;
        case 3: return colorYellow;
        case 4: return colorBlack;
        case 5: return colorWhite;
        default: return colorBlack;
    }
}