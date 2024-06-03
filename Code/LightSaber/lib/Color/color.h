#pragma once

#include <Arduino.h>

namespace Color
{
    // 32-bit color value. Most significant byte is white (for RGBW
    // pixels) or ignored (for RGB pixels), next is red, then green,
    // and least significant byte is blue.
    // e.g. 0x00RRGGBB
    typedef uint32_t Color;
    typedef float FloatColor;

    Color add(Color a, Color b);

    Color multiply(Color a, u_int32_t b);

    Color multiplyScalar(Color c, float s);

    Color gammaCorrect(Color c, float gamma);

    Color applyBrightness(Color color, u_int8_t brightness);

    Color fromFloatColor(FloatColor c);
    FloatColor toFloatColor(Color c);

    String colorToStringCompact(Color c);
}