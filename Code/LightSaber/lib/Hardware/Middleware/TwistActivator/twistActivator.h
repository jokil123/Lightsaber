#pragma once

#include <updatingComponent.h>
#include <Gyroscope/gyroscope.h>

class TwistActivator : public IUpdatingComponent
{
    Gyroscope &gyro;
    ulong cooldownMicros;
    float gate;

    ulong lastActivationMicros;
    bool active;

public:
    TwistActivator(Gyroscope &gyro, float gate, float cooldown);

    void update();

    // true on the update where the user starts twisting
    bool getActivated();
};