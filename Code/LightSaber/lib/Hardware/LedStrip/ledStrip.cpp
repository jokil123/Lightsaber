#include "ledStrip.h"

#include <frameBuffer.h>

LedStrip::LedStrip(int pin, int count) : strip(count, pin, NEO_GRB + NEO_KHZ800)
{
    strip.begin();
    strip.fill(0xFFFFFF, 0, LED_STRIP_COUNT);
    strip.setBrightness(255);
    strip.show();

    // Serial.print("Strip Pin:");
    // Serial.println(strip.getPin());

    // Serial.print("Strip Count:");
    // Serial.println(strip.numPixels());

    // Serial.println("Strip Initialized");
};

void LedStrip::blitStrip(FrameBuffer frameBuffer)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        strip.setPixelColor(i, frameBuffer.buffer[i]);
    }

    strip.show();
}

void LedStrip::setBrightness(uint8_t b)
{
    strip.setBrightness(b);
};