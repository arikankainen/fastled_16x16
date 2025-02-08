#include <Arduino.h>
#include <FastLED.h>

#define BUTTON1_PIN 3
#define BUTTON2_PIN 4
#define BUTTON3_PIN 5
#define DATA_PIN 6

#define NUM_LEDS 256
#define PIXELS_X 16
#define PIXELS_Y 16
#define COLORS 3
#define R 0
#define G 1
#define B 2

extern CRGB leds[NUM_LEDS];
