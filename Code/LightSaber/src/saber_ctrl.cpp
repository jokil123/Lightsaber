#include "saber_ctrl.h"

#include <pushbuttons.h>

#include <Arduino.h>
#include <memory>

SaberState saberState;
const float EXTENSION_DURATION = 0.5; // seconds

// Call this function to update the saber state
void updateSaberState(float dt)
{

    if (saberState.extensionDirection == 0 && getButton0() == HIGH)
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

    saberState.extention += dt / EXTENSION_DURATION * saberState.extensionDirection;

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
}

// getSaberState returns a borrowed reference to the saber state
SaberState &getSaberState()
{
    return saberState;
}