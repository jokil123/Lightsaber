#include "mix.h"

#include "const.h"
#include "color.h"

// This is a simple function that adds two FrameBuffers together.
// It will add the color values of each pixel in b to the corresponding pixel in a.
// a will be modified in place, b will not be modified.
void frameAdd(FrameBuffer a, FrameBuffer b)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        a[i] = colorAdd(a[i], b[i]);
    }
}

void frameMultiply(FrameBuffer a, FrameBuffer b)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        a[i] = colorMultiply(a[i], b[i]);
    }
}