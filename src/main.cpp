#include "def.h"
#include "colors.h"
#include "pixels.h"
#include "font-big.h"
#include "font-small.h"
#include "text.h"
#include "frames.h"

void setup() {
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
    FastLED.setBrightness(3); // NOTE! Keep brightness under 10 so that the LEDs don't draw too much current
    Serial.begin(9600);
    clearPixels(matrix, true);
}

void loop() {
    uint8_t n = 0;
    for (int8_t i = -16; i < 32; i++) {
        clearPixels(matrix);
        if (n == 0) {
            setFrame(matrix, frameFireball, false, 0, i - 16, 0);
            setFrame(matrix, frameRun1, false, 0, i, 0);
        }
        if (n == 1) {
            setFrame(matrix, frameFireball, false, 90, i - 16, 0);
            setFrame(matrix, frameRun2, false, 0, i, 0);
        }
        if (n == 2) {
            setFrame(matrix, frameFireball, false, 180, i - 16, 0);
            setFrame(matrix, frameRun3, false, 0, i, 0);
        }
        if (n == 3) {
            setFrame(matrix, frameFireball, false, 270, i - 16, 0);
            setFrame(matrix, frameRun2, false, 0, i, 0);
        }

        updateDisplay(matrix);
        delay(100);

        n++;
        if (n > 3) n = 0;
    }

    delay(1000);

    for (int8_t i = 16; i > -32; i--) {
        clearPixels(matrix);
        if (n == 0) {
            setFrame(matrix, frameFireball, true, 0, i + 16, 0);
            setFrame(matrix, frameRun1, true, 0, i, 0);
        }
        if (n == 1) {
            setFrame(matrix, frameFireball, true, 270, i + 16, 0);
            setFrame(matrix, frameRun2, true, 0, i, 0);
        }
        if (n == 2) {
            setFrame(matrix, frameFireball, true, 180, i + 16, 0);
            setFrame(matrix, frameRun3, true, 0, i, 0);
        }
        if (n == 3) {
            setFrame(matrix, frameFireball, true, 90, i + 16, 0);
            setFrame(matrix, frameRun2, true, 0, i, 0);
        }

        updateDisplay(matrix);
        delay(100);

        n++;
        if (n > 3) n = 0;
    }

    delay(1000);

    // clearPixels(matrix);
    // setFrame(matrix, frameStand, true, 0, 2, 0, true);
    // delay(1000);

    // clearPixels(matrix);
    // setFrame(matrix, frameStand, true, 0, -2, 0, true);
    // delay(1000);

    // clearPixels(matrix);
    // setFrame(matrix, frameStand, true, 270, 2, 0, true);
    // delay(1000);

    // clearPixels(matrix);
    // setFrame(matrix, frameStand, true, 270, -2, 0, true);
    // delay(1000);

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
