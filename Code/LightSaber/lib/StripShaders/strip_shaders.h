#pragma once

#include <const.h>

void fillPartial(FrameBuffer frameBuffer, Color color, float from, float to);

void sine(FrameBuffer frameBuffer, Color color, float frequency, float amplitude, float phase, float offset, bool shiftPositive);

void fill(FrameBuffer frameBuffer, Color color);

void clear(FrameBuffer frameBuffer);

void frameMap(FrameBuffer frameBuffer, std::function<Color(int)> f);