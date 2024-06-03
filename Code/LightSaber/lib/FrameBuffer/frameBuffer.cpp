#include "frameBuffer.h"

#include <const.h>

void FrameBuffer::clear()
{
    fill(0x000000);
}

void FrameBuffer::fill(Color::Color color)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        buffer[i] = color;
    }
}

void FrameBuffer::fillPartial(Color::Color color, float from, float to)
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
        buffer[i] = color;
    }
}

void FrameBuffer::fillSine(Color::Color color, float frequency, float amplitude, float phase, float offset, bool shiftPositive)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        float value = sin(frequency * i + phase) * amplitude;
        if (shiftPositive)
        {
            value = ((value + amplitude) / 2.) + offset;
        }

        float clampedValue = max(0.0f, min(1.0f, value));

        buffer[i] = Color::multiplyScalar(color, clampedValue);
    }
}

void FrameBuffer::map(std::function<Color::Color(int)> f)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        buffer[i] = f(i);
    }
}

// pretty prints the frame buffer to serial in the following format:
// ```
//       0   1   2   3   4   5   6   7   8   9
// 010 FFF 14B 12E FFF 14B 12E FFF 14B 12E 1BA
// 020 FFF 14B 12E FFF 14B 12E FFF 14B 12E 1BA
// ```
void FrameBuffer::serialPrintFrameBuffer(FrameBuffer frameBuffer)
{
    String str = "      0   1   2   3   4   5   6   7   8   9\n";

    for (int row = 0; row <= round(LED_STRIP_COUNT / 10); row++)
    {
        if (row < 10)
            str += "0";

        str += String(row * 10, DEC);

        if (row == 0)
            str += "0";

        for (int col = 0; col < 10; col++)
        {
            int index = row * 10 + col;
            if (index < LED_STRIP_COUNT)
            {
                str += " ";
                str += Color::colorToStringCompact(buffer[index]);
            }
        }

        str += "\n";
    }

    Serial.println(str.c_str());
}