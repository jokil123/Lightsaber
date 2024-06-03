#pragma once

#include <const.h>
#include <color.h>
#include "Lut/lut.h"

class FrameBuffer
{
public:
    Color::Color buffer[LED_STRIP_COUNT];

    void clear();
    void fill(Color::Color color);
    void fillPartial(Color::Color color, float from, float to);
    void fillSine(Color::Color color, float frequency, float amplitude, float phase, float offset, bool shiftPositive);
    void map(std::function<Color::Color(int)> f);
    void serialPrintFrameBuffer(FrameBuffer frameBuffer);

    void applyLut(Lut::BWLut lut);

    void blendAdd(FrameBuffer &b);
    void blendMultiply(FrameBuffer &b);
};