#include "def.h"
#include "pixels.h"
#include "frames.h"

void animRunRightWithFireball() {
    uint8_t n = 0;

    for (int8_t i = -16; i < 32; i++) {
        clearPixels(matrix);

        switch (n) {
            case 0:
                setFrame(matrix, frameFireball, false, 0, i - 16, 0);
                setFrame(matrix, frameRun1, false, 0, i, 0);
                break;
            case 1:
                setFrame(matrix, frameFireball, false, 90, i - 16, 0);
                setFrame(matrix, frameRun2, false, 0, i, 0);
                break;
            case 2:
                setFrame(matrix, frameFireball, false, 180, i - 16, 0);
                setFrame(matrix, frameRun3, false, 0, i, 0);
                break;
            case 3:
                setFrame(matrix, frameFireball, false, 270, i - 16, 0);
                setFrame(matrix, frameRun2, false, 0, i, 0);
                break;
        }

        updateDisplay(matrix);
        delay(100);

        n++;
        if (n > 3) n = 0;
    }
}

void animRunLeftWithFireball() {
    uint8_t n = 0;

    for (int8_t i = 16; i > -32; i--) {
        clearPixels(matrix);

        switch (n) {
            case 0:
                setFrame(matrix, frameFireball, true, 0, i + 16, 0);
                setFrame(matrix, frameRun1, true, 0, i, 0);
                break;
            case 1:
                setFrame(matrix, frameFireball, true, 270, i + 16, 0);
                setFrame(matrix, frameRun2, true, 0, i, 0);
                break;
            case 2:
                setFrame(matrix, frameFireball, true, 180, i + 16, 0);
                setFrame(matrix, frameRun3, true, 0, i, 0);
                break;
            case 3:
                setFrame(matrix, frameFireball, true, 90, i + 16, 0);
                setFrame(matrix, frameRun2, true, 0, i, 0);
                break;
        }

        updateDisplay(matrix);
        delay(100);

        n++;
        if (n > 3) n = 0;
    }
}

void animRunRightInPlaceAndTurnLeft() {
    for (uint8_t i = 0; i < 10; i++) {
        clearPixels(matrix);
        setFrame(matrix, frameRun1, false, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun2, false, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun3, false, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun2, false, 0, 0, 0, true);
        delay(100);
    }

    clearPixels(matrix);
    setFrame(matrix, frameTurn, true, 0, 0, 0, true);
    delay(500);

    clearPixels(matrix);
    setFrame(matrix, frameStand, true, 0, 0, 0, true);
    delay(3000);
}

void animRunLeftInPlaceAndTurnRight() {
    for (uint8_t i = 0; i < 10; i++) {
        clearPixels(matrix);
        setFrame(matrix, frameRun1, true, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun2, true, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun3, true, 0, 0, 0, true);
        delay(100);

        clearPixels(matrix);
        setFrame(matrix, frameRun2, true, 0, 0, 0, true);
        delay(100);
    }

    clearPixels(matrix);
    setFrame(matrix, frameTurn, false, 0, 0, 0, true);
    delay(500);

    clearPixels(matrix);
    setFrame(matrix, frameStand, false, 0, 0, 0, true);
    delay(3000);
}

void animRunRightAndJumpOverKoopa() {
    uint8_t n = 0;
    uint8_t h = 0;

    const uint8_t JUMP_FRAMES = 22;
    const uint8_t JUMP_HEIGHT = 16;

    for (int8_t i = -16; i < 16; i++) {
        clearPixels(matrix);

        if (i < -6) {
            switch (n) {
                case 0:
                    setFrame(matrix, frameRun1, false, 0, i, 0);
                    break;
                case 1:
                    setFrame(matrix, frameRun2, false, 0, i, 0);
                    break;
                case 2:
                    setFrame(matrix, frameRun3, false, 0, i, 0);
                    break;
                case 3:
                    setFrame(matrix, frameRun2, false, 0, i, 0);
                    break;
            }
        
            n++;
            if (n > 3) n = 0;
        }
        else {
            int8_t y = -JUMP_HEIGHT * sin((M_PI / JUMP_FRAMES) * h);
            setFrame(matrix, frameJump, false, 0, i, y - 1);
            setFrame(matrix, frameKoopa, false, 0, 15 - i * 2, 1);
            h++;
        }

        updateDisplay(matrix);
        delay(100);
    }

}