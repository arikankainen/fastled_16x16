#include <Arduino.h>
#include "def.h"
#include "pixels.h"

uint8_t convertCharacter(uint8_t character) {
    if (character == 165) character = 123;         // å
    else if (character == 164) character = 124;    // ä
    else if (character == 182) character = 125;    // ö
    else if (character == 133) character = 91;     // Å
    else if (character == 132) character = 92;     // Ä
    else if (character == 150) character = 93;     // Ö
    else if (character == 195) character = 0;      // ääkkösen eka merkki (195+???)
    if (character > 96 && character < 126) character -= 32;

    return character;
}

int getTextWidth(const uint8_t font[], const char *text) {
    int textWidth = 0;
    size_t stringLength = strlen(text);

    for (uint8_t i = 0; i < stringLength; i++) {
        uint8_t character = convertCharacter(text[i]);

        if (character == 0) continue;

        int location = (character - 32) * 8;                            // Merkin sijainti "characters"-arrayssa (ensimmäinen merkki on asciin 32:s merkki)
        uint8_t charactedWidth = pgm_read_byte(&font[location + 7]);    // Merkin pituus "characters"-arraysta (jokaisen merkin kahdeksas rivi)

        textWidth += charactedWidth;
    }

    return textWidth - 1;
}

// void scrollText(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], const uint8_t font[], const char *text, uint8_t row, uint8_t spaces, int scrollDelay) {
//     size_t stringLength = strlen(text);    // Scrollattavan tekstin pituus

//     for (uint8_t i = 0; i < stringLength + spaces; i++) {    // Käydään teksti läpi merkki merkiltä (lisänä "spaces" määrä tyhjiä pikseleitä)
//         uint8_t character = convertCharacter(text[i]);

//         if (character == 0) continue;

//         int location = (character - 32) * 8;                   // Merkin sijainti "characters"-arrayssa (ensimmäinen merkki on asciin 32:s merkki)
//         uint8_t width = pgm_read_byte(&font[location + 7]);    // Merkin pituus "characters"-arraysta (jokaisen merkin kahdeksas rivi)

//         if (i >= stringLength) width = 1;    // Jos mennään yli tekstin pituuden, lisättävä tyhjä pituus 1 pikseli

//         for (uint8_t col = 0; col < width; col++) {
//             movePixelsLeftRow(matrix, row, 1, false);    // Siirretään rivin jokainen pikseli vasemmalle

//             for (uint8_t y = 0 + (row * 8); y < 7 + (row * 8); y++) {
//                 bool pixel = (pgm_read_byte(&font[y - (row * 8) + location]) >> (7 - col)) & 1;    // Luetaan "characters"-arraysta onko pikseli päällä vai ei

//                 if (i < stringLength) {
//                     matrix[7][y] ^= (-pixel ^ matrix[7][y]) & (1 << (0));    // Merkitään näytön puskurin oikeaan reunaan onko pikseli päällä vai ei
//                 }
//             }

//             max7219_UpdateDisplayRow(matrix, row);    // Päivitetään näyton rivi

//             if (scrollDelay > 0) delay(scrollDelay);    // Hidastetaan
//         }
//     }
// }

void setText(uint8_t matrix[PIXELS_X][PIXELS_Y][COLORS], const uint8_t font[], const char *text, uint8_t x, uint8_t y, uint16_t scrollDelay, bool inverted, bool refresh) {
    size_t len = strlen(text);

    for (uint8_t i = 0; i < len; i++) {
        uint8_t character = convertCharacter(text[i]);

        if (character == 0) continue;

        int location = (character - 32) * 8;
        uint8_t width = pgm_read_byte(&font[location + 7]);

        for (uint8_t x2 = 0; x2 < width; x2++) {
            for (uint8_t y2 = 0; y2 < 7; y2++) {
                bool pixel = (pgm_read_byte(&font[y2 + location]) >> (7 - x2)) & 1;

                if (pixel) {
                    if (inverted) clearPixel(matrix, x2 + x, y2 + y, false);
                    else setPixel(matrix, x2 + x, y2 + y, 255, 255, 255, false);
                }
            }
        }

        if (scrollDelay > 0 && refresh) {
            delay(scrollDelay);
            updateDisplay(matrix);
        }

        x += width;
    }

    if (refresh) updateDisplay(matrix);
}