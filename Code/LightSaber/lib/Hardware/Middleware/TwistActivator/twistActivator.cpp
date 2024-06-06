#include "twistActivator.h"
#include <genericUtil.h>

TwistActivator::TwistActivator(Gyroscope &gyro, float gate, float cooldown) : gyro(gyro), gate(gate)
{
    cooldownMicros = cooldown * 1000000;
}

void TwistActivator::update()
{
    active = false;

    // serialPlot("time-since", micros() - lastActivationMicros);
    // serialPlot("could?", micros() - lastActivationMicros > cooldownMicros);

    if (micros() - lastActivationMicros < cooldownMicros)
        return;

    if (abs(gyro.getTwist()) < gate)
        return;

    // Serial.println("TWISTSTS");

    active = true;
    lastActivationMicros = micros();
}

// true on the update where the user starts twisting
bool TwistActivator::getActivated()
{
    return active;
}