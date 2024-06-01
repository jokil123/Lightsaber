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
#include "saber_ctrl.h"
#include <pushbuttons.h>

void draw();
BWLut lut;

void setup()
{
    Serial.begin(9600);

    initLedIndicator();

    initStrip();
    initPushButtons();

    setBrightness(255);

    addSaberProfile({0.3, 0xFF0000});
    addSaberProfile({0.5, 0x00FF00});
    addSaberProfile({0.6, 0x0000FF});
    addSaberProfile({0.3, 0xFF00FF});
    addSaberProfile({0.3, 0xff7f00});

    // auto gamma = [](Color c)
    // { return gammaCorrect(c, 1); };
    // generateBWLut(lut, gamma);

    // Serial.println(lutToString(lut));

    Serial.print("\n");
    Serial.println("Setup done");
}

int lastFrameTime = 0;
int lastUpdateTime = 0;
void loop()
{
    float dt = (millis() - lastUpdateTime) / 1000.0;
    lastUpdateTime = millis();

    updateSaberState(dt);

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

    fill(frameBuffer, 0x000000);

    // sine(frameBuffer, 0xFF0000, 0.5, 1, (float)drawTime / 250, 0.01, true);

    SaberProfile profile = getCurrentSaberProfile();

    fillPartial(frameBuffer, profile.baseColor, 1, 1 - getSaberState().extention / 2);
    fillPartial(frameBuffer, profile.baseColor, 0, getSaberState().extention / 2);
    // fill(frameBuffer, getSaberState().extention);
    // Serial.println(getSaberState().extention);j

    blitStrip(frameBuffer);
}