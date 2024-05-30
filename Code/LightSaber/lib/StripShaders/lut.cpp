#include "lut.h"

#include <tuple>
#include <const.h>
#include <functional>
#include "color.h"

// generates a lut from a function
void generateBWLut(BWLut lut, std::function<Color(Color)> f)
{
    for (int i = 0; i < 256; i++)
    {
        lut[i] = f(i);
    }
}

// applies a lut to a frame buffer
void applyLut(FrameBuffer frameBuffer, BWLut lut)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        uint8_t r = (frameBuffer[i] >> 16) & 0xFF;
        uint8_t g = (frameBuffer[i] >> 8) & 0xFF;
        uint8_t b = frameBuffer[i] & 0xFF;

        uint16_t brightness = (r + g + b) / 3;

        frameBuffer[i] = applyBrightness(frameBuffer[i], lut[(uint8_t)brightness]);
    }
}

// combines two luts by applying one to the other
// This is like a layering adjustment in photoshop
// vvv top  vvv
// --- base ---
void combineLuts(BWLut base, BWLut top)
{
    for (int i = 0; i < 256; i++)
    {
        base[i] = top[base[i]];
    }
}

String lutToString(BWLut lut)
{
    String s = "";
    for (int i = 0; i < 256; i++)
    {
        s += String(lut[i], DEC) + " ";
    }
    return s;
}