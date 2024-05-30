#include "util.h"
// #include <fmt/core.h>
#include <Arduino.h>

template <typename T>
int sign(T val)
{
    return (T(0) < val) - (val < T(0));
}

template <typename T>
int clamp(T val, T min, T max)
{
    return val < min ? min : (val > max ? max : val);
}

// pretty prints the frame buffer to serial in the following format:
// ```
//       0   1   2   3   4   5   6   7   8   9
// 010 FFF 14B 12E FFF 14B 12E FFF 14B 12E 1BA
// 020 FFF 14B 12E FFF 14B 12E FFF 14B 12E 1BA
// ```
void printFrameBuffer(FrameBuffer frameBuffer)
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
                str += colorToStringCompact(frameBuffer[index]);
            }
        }

        str += "\n";
    }

    Serial.println(str.c_str());
}

// formats a color to a string in the format "RGB" using the most significant bits of each color channel
// e.g. 0xABCDEF -> "ACE"
String colorToStringCompact(Color color)
{
    String str = "";
    str += String((color & 0x00F00000) >> 20, HEX);
    str += String((color & 0x0000F000) >> 12, HEX);
    str += String((color & 0x000000F0) >> 4, HEX);
    return str;
}