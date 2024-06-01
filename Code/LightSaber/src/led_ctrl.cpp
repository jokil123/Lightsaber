#include "led_ctrl.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel WS2812B = Adafruit_NeoPixel(LED_STRIP_COUNT, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

// TODO: Change this to use the FastLED library and find a way to just pass the frame buffer to the strip instead of having to call setPixelColor for each pixel
void blitStrip(FrameBuffer frameBuffer)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        WS2812B.setPixelColor(i, frameBuffer[i]);
    }

    WS2812B.show();
}

void initStrip()
{
    WS2812B.begin();
}

void setBrightness(uint8_t b)
{
    WS2812B.setBrightness(b);
}