#include "stateManager.h"

#include <Arduino.h>
#include <hardware.h>

SaberState &StateManager::update(SaberProfile &profile)
{
    float dt = (micros() - lastUpdateTime) / 1000000.0f;
    lastUpdateTime = micros();

    if (saberState.extensionDirection == 0 && (Hardware::getInstance().button0.getKeyDown() || abs(Hardware::getInstance().gyroscope.getTwist()) > 150))
    {
        if (saberState.extention == 0)
        {
            saberState.extensionDirection = 1;
        }
        else if (saberState.extention == 1)
        {
            saberState.extensionDirection = -1;
        }
    }

    saberState.extention += dt / profile.extensionDuration * saberState.extensionDirection;

    if (saberState.extention >= 1)
    {
        saberState.extention = 1;
        saberState.extensionDirection = 0;
    }
    else if (saberState.extention <= 0)
    {
        saberState.extention = 0;
        saberState.extensionDirection = 0;
    }

    return saberState;
}