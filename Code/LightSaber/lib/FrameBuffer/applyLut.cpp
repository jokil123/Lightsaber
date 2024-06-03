#include "frameBuffer.h"
#include <Lut/lut.h>

// applies a lut to a frame buffer
void FrameBuffer::applyLut(Lut::BWLut lut)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        uint8_t r = (buffer[i] >> 16) & 0xFF;
        uint8_t g = (buffer[i] >> 8) & 0xFF;
        uint8_t b = buffer[i] & 0xFF;

        uint16_t brightness = (r + g + b) / 3;

        buffer[i] = Color::applyBrightness(buffer[i], lut[(uint8_t)brightness]);
    }
}