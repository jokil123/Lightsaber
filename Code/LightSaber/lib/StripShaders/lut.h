#pragma once

#include <const.h>
#include <functional>

typedef uint8_t BWLut[256];

void generateBWLut(BWLut lut, std::function<Color(Color)> f);

void applyLut(FrameBuffer frameBuffer, BWLut lut);

void combineLuts(BWLut base, BWLut top);

String lutToString(BWLut lut);