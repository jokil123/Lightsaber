#pragma once

#include <Arduino.h>

#include "pinout.h"

#define LED_STRIP_COUNT 288
// #define FRAME_RATE 110
#define FRAME_RATE 110

// 32-bit color value. Most significant byte is white (for RGBW
// pixels) or ignored (for RGB pixels), next is red, then green,
// and least significant byte is blue.
// e.g. 0x00RRGGBB
typedef uint32_t Color;
typedef float FloatColor;
typedef Color FrameBuffer[LED_STRIP_COUNT];