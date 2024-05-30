#include "led_ctrl.h"

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel WS2812B = Adafruit_NeoPixel(LED_STRIP_COUNT, LED_STRIP_PIN, NEO_GRB + NEO_KHZ800);

void blitStrip(FrameBuffer frameBuffer)
{
    for (int i = 0; i < LED_STRIP_COUNT; i++)
    {
        WS2812B.setPixelColor(i, frameBuffer[i]);
    }

    WS2812B.show();
}

void setBrightness(uint8_t b)
{
    WS2812B.setBrightness(b);
}