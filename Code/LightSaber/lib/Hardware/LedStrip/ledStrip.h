#pragma once

#include <Adafruit_NeoPixel.h>
#include <const.h>
#include <frameBuffer.h>

class LedStrip
{
    Adafruit_NeoPixel strip;

public:
    LedStrip(int pin, int count);
    void blitStrip(FrameBuffer frameBuffer);
    void setBrightness(uint8_t b);
};