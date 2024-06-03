#include "stateManager.h"

#include <Arduino.h>
#include <hardware.h>

SaberState &StateManager::update(SaberProfile &profile)
{

    float dt = (micros() - lastUpdateTime) / 1000000.0f;
    lastUpdateTime = micros();

    // Serial.print(">dt:");
    // Serial.println(dt);

    // Serial.print(">extention:");
    // Serial.println(saberState.extention);

    // Serial.print(">extensionDirection:");
    // Serial.println(saberState.extensionDirection);

    if (saberState.extensionDirection == 0 && Hardware::getInstance().button0.getKeyDown())
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