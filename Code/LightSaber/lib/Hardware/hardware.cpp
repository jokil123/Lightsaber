#include "hardware.h"

#include "pinout.h"

#include <LedStrip/ledStrip.h>
#include <Pushbutton/pushbutton.h>

Hardware &Hardware::getInstance()
{
    static Hardware instance;
    return instance;
}

Hardware::Hardware() : button0(BUTTON0_PIN), button1(BUTTON1_PIN), ledStrip(LED_STRIP_PIN, LED_STRIP_COUNT), gyroscope(GYRO_CS_PIN, GYRO_INT_PIN) { return; };

void Hardware::update()
{
    button0.update();
    button1.update();
    gyroscope.update();
}