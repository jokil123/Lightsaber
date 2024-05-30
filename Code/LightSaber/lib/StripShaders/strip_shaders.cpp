#include "strip_shaders.h"

#include "const.h"
#include "color.h"

#include <Arduino.h>
#include <util.h>

// a strip shader is a function that takes a frame buffer and modifies it

// fills a portion of the frame buffer with a color from a percentage of the strip to another percentage of the strip
void fillPartial(FrameBuffer frameBuffer, Color color, float from, float to)
{
    // switch from and to if from is greater than to
    if (from > to)
    {
        float temp = from;
        from = to;
        to = temp;
    }

    int fromIndex = round((LED_STRIP_COUNT - 1) * from);
    int toIndex = round((LED_STRIP_COUNT - 1) * to);

    for (int i = fromIndex; i <= toIndex; i++)
    {
        frameBuffer[i] = color;
    }
}

void sine(FrameBuffer frameBuffer, Color color, float frequency, float amplitude, float phase, float offset, bool shiftPositive)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        float value = sin(frequency * i + phase) * amplitude;
        if (shiftPositive)
        {
            value = ((value + amplitude) / 2.) + offset;
        }

        float clampedValue = max(0.0f, min(1.0f, value));

        frameBuffer[i] = colorMultiplyScalar(color, clampedValue);
    }
}

// fills the entire frame buffer with a color
void fill(FrameBuffer frameBuffer, Color color)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        frameBuffer[i] = color;
    }
}

void frameMap(FrameBuffer frameBuffer, std::function<Color(int)> f)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        frameBuffer[i] = f(i);
    }
}

// clears the entire frame buffer
void clear(FrameBuffer frameBuffer)
{
    fill(frameBuffer, 0x000000);
}