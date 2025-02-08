#ifndef FRAMES_H
#define FRAMES_H

#include <Arduino.h>

uint8_t frameStand[16][16] = {
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 2, 3, 3, 2, 3, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, },
    { 0, 0, 0, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 2, 1, 2, 2, 1, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, },
    { 0, 0, 3, 3, 2, 1, 3, 1, 1, 3, 1, 2, 3, 3, 0, 0, },
    { 0, 0, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 0, 0, },
    { 0, 0, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 0, 0, },
    { 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, },
};

uint8_t frameRun1[16][16] = {
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 2, 3, 3, 2, 3, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, },
    { 0, 0, 0, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 0, 0, },
    { 3, 3, 2, 2, 2, 2, 1, 1, 1, 2, 2, 2, 3, 3, 3, 0, },
    { 3, 3, 3, 0, 2, 2, 1, 3, 1, 1, 1, 2, 2, 3, 3, 0, },
    { 3, 3, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 2, 0, 0, },
    { 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, },
    { 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 0, 0, },
    { 0, 2, 2, 1, 1, 1, 0, 0, 0, 1, 1, 1, 2, 2, 0, 0, },
    { 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};

uint8_t frameRun2[16][16] = {
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 2, 3, 3, 2, 3, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, 0, },
    { 0, 0, 0, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, },
    { 0, 0, 0, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 1, 2, 2, 2, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 2, 2, 1, 1, 2, 2, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 2, 1, 1, 3, 1, 1, 3, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 1, 2, 2, 3, 3, 3, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 1, 2, 3, 3, 1, 1, 1, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 1, 1, 1, 2, 2, 2, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, },
};

uint8_t frameRun3[16][16] = {
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 2, 2, 2, 3, 3, 2, 3, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 3, 2, 3, 3, 3, 2, 3, 3, 3, 0, 0, },
    { 0, 0, 0, 0, 2, 3, 2, 2, 3, 3, 3, 2, 3, 3, 3, 0, },
    { 0, 0, 0, 0, 2, 2, 3, 3, 3, 3, 2, 2, 2, 2, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 2, 2, 2, 2, 1, 2, 0, 3, 0, 0, 0, },
    { 0, 0, 0, 0, 3, 2, 2, 2, 2, 2, 2, 3, 3, 3, 0, 0, },
    { 0, 0, 0, 3, 3, 1, 2, 2, 2, 2, 2, 3, 3, 0, 0, 0, },
    { 0, 0, 0, 2, 2, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 2, 2, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0, },
    { 0, 0, 2, 0, 0, 0, 0, 2, 2, 2, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, },
};

uint8_t frameTurn[16][16] = {
    { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 2, 2, 2, 3, 2, 3, 0, 0, 0, 0, 0, },
    { 0, 3, 3, 2, 3, 3, 2, 3, 3, 3, 3, 3, 3, 0, 0, 0, },
    { 0, 3, 3, 2, 3, 3, 2, 2, 3, 3, 2, 2, 3, 3, 0, 0, },
    { 0, 0, 3, 3, 2, 3, 3, 3, 3, 3, 3, 2, 2, 0, 0, 0, },
    { 0, 0, 0, 1, 1, 1, 2, 2, 1, 3, 3, 0, 0, 0, 0, 0, },
    { 0, 0, 1, 1, 3, 3, 3, 2, 1, 1, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 1, 2, 3, 3, 3, 2, 2, 2, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 1, 1, 1, 3, 3, 2, 2, 2, 2, 2, 2, 0, 0, 0, },
    { 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 0, 0, 0, 0, },
    { 0, 0, 0, 1, 2, 2, 2, 1, 1, 1, 1, 0, 0, 0, 0, 0, },
    { 0, 0, 0, 0, 2, 2, 2, 2, 1, 1, 1, 0, 0, 0, 0, 0, },
    { 0, 2, 0, 2, 1, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, },
    { 0, 2, 2, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
    { 0, 0, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, },
};

#endif // FRAMES_H