#pragma once
#include <const.h>

Color colorAdd(Color a, Color b);

Color colorMultiply(Color a, u_int32_t b);

Color colorMultiplyScalar(Color c, float s);

Color gammaCorrect(Color c, float gamma);

Color applyBrightness(Color color, u_int8_t brightness);