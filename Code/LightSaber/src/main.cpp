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

void setup()
{
    Serial.begin(9600);
    initLedIndicator();

    ComponentUpdater &compU = ComponentUpdater::getInstance();

    Hardware &hw = Hardware::getInstance();
    compU.addComponent(&hw);

    hw.ledStrip.setBrightness(255);

    // This will leak memory
    // Too bad!
    ProfileManager *pm = new ProfileManager();
    pm->addProfile({0.3, 0xFF0000});
    pm->addProfile({0.5, 0x00FF00});
    pm->addProfile({0.6, 0x0000FF});
    pm->addProfile({0.3, 0xFF00FF});
    pm->addProfile({0.3, 0xff7f00});
    pm->addProfile({0.3, 0xff3300});
    pm->addProfile({0.3, 0xffffff7});

    // All of these will also leak memory!
    StateManager *sm = new StateManager();
    SaberRenderer *sr = new SaberRenderer();
    SaberSynth *ss = new SaberSynth();

    // In all honesty though it doesn't really matter as for this function to be executed twice you'd need to reset the device
    SaberController *sc = new SaberController(*pm, *sm, *sr, *ss);
    compU.addComponent(sc);

    Serial.print("\n");
    Serial.println("Setup done");
}

void loop()
{
    ComponentUpdater::getInstance().updateAll();
}
