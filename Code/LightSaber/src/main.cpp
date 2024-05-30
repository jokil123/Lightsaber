#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include "led_ctrl.h"
#include "init_led.h"

#include <const.h>
#include <strip_shaders.h>
#include <mix.h>
#include <util.h>
#include <lut.h>
#include <color.h>

void draw();
BWLut lut;

void setup()
{
    init_led();

    Serial.begin(9600);
    setBrightness(255);

    auto gamma = [](Color c)
    { return gammaCorrect(c, 1); };
    generateBWLut(lut, gamma);

    Serial.println(lutToString(lut));

    Serial.print("\n");
    Serial.println("Setup done");
}

int lastFrameTime = 0;
void loop()
{
    if (millis() - lastFrameTime > 1000 / FRAME_RATE)
    {
        lastFrameTime = millis();
        draw();
    }
}

void draw()
{
    int drawTime = millis();
    FrameBuffer frameBuffer;
    // fill(frameBuffer, 0x000000);

    // FrameBuffer fb2;
    // fill(fb2, 0x00FF00);
    // frameAdd(frameBuffer, fb2);

    // FrameBuffer fb3;
    // fill(fb3, 0x0000FF);
    // frameAdd(frameBuffer, fb3);

    // sine(frameBuffer, 0xFFFFFF, 0.1, 1, (float)drawTime / 1000, false);
    sine(frameBuffer, 0xFF0000, 0.5, 1, (float)drawTime / 250, 0.01, true);
    // fillPartial(frameBuffer, 0xFF0000, 0.0, 0.5);
    // fillPartial(frameBuffer, 0x00FF00, 0.5, 1.0);

    // Serial.println("Frame buffer done in " + String(millis() - drawTime) + "ms");
    // Serial.print(".");
    // printFrameBuffer(frameBuffer);

    // Serial.println("Frame buffer done in " + String(millis() - drawTime) + "ms");
    // printFrameBuffer(frameBuffer);

    // applyLut(frameBuffer, lut);

    // auto f = [frameBuffer](int i)
    // {
    //     return applyBrightness(frameBuffer[i], 10);
    // };
    // frameMap(frameBuffer, f);

    // printFrameBuffer(frameBuffer);

    blitStrip(frameBuffer);
}