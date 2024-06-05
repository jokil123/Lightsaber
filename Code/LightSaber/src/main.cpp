#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#include <LedBuiltin/ledBuiltin.h>

#include <const.h>
#include <util.h>
#include <color.h>
#include <hardware.h>
#include <componentUpdater.h>
#include <saberController.h>
#include <MemoryFree.h>
#include <tuple>

void setup()
{
    Serial.begin(9600);
    initLedIndicator();

    ComponentUpdater &compU = ComponentUpdater::getInstance();

    Hardware &hw = Hardware::getInstance();
    compU.addComponent(&hw);

    // hw.ledStrip.setBrightness(255);

    // // This will leak memory
    // // Too bad!
    // ProfileManager *pm = new ProfileManager();
    // pm->addProfile({0.3, 0xFF0000});
    // pm->addProfile({0.5, 0x00FF00});
    // pm->addProfile({0.6, 0x0000FF});
    // pm->addProfile({0.3, 0xFF00FF});
    // pm->addProfile({0.3, 0xff7f00});
    // pm->addProfile({0.3, 0xff3300});
    // pm->addProfile({0.3, 0xffffff});
    // pm->addProfile({0.3, 0x010101});

    // // All of these will also leak memory!
    // StateManager *sm = new StateManager();
    // SaberRenderer *sr = new SaberRenderer();
    // SaberSynth *ss = new SaberSynth();

    // // In all honesty though it doesn't really matter as for this function to be executed twice you'd need to reset the device
    // SaberController *sc = new SaberController(*pm, *sm, *sr, *ss);
    // compU.addComponent(sc);

    // Serial.print("\n");
    // Serial.println("Setup done");
}

void loop()
{
    ComponentUpdater::getInstance().updateAll();

    // Serial.print(">twist:");
    // Serial.println(Hardware::getInstance().gyroscope.getTwist());

    // Serial.print(">steve:");
    // Serial.println(Hardware::getInstance().gyroscope.getSteve());

    Serial.print(">rx:");
    Serial.println(std::get<0>(Hardware::getInstance().gyroscope.getOrientation()));

    Serial.print(">ry:");
    Serial.println(std::get<1>(Hardware::getInstance().gyroscope.getOrientation()));

    Serial.print(">rz:");
    Serial.println(std::get<2>(Hardware::getInstance().gyroscope.getOrientation()));
}
