#include "frameBuffer.h"

#include "const.h"
#include "color.h"

// This is a simple function that adds two FrameBuffers together.
// It will add the color values of each pixel in b to the corresponding pixel in a.
// a will be modified in place, b will not be modified.
void FrameBuffer::blendAdd(FrameBuffer &b)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        buffer[i] = Color::add(buffer[i], b.buffer[i]);
    }
}

void FrameBuffer::blendMultiply(FrameBuffer &b)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        buffer[i] = Color::multiply(buffer[i], b.buffer[i]);
    }
}