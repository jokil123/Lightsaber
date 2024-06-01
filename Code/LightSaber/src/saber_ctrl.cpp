#include "saber_ctrl.h"

#include <pushbuttons.h>

#include <Arduino.h>
#include <memory>
#include <vector>

SaberState saberState;
int currentProfileIndex;
std::vector<SaberProfile> profiles = std::vector<SaberProfile>();

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

    // if button 1 is pressed switch to the next profile
    if (getButton1() == HIGH)
    {
        activateSaberProfile((currentProfileIndex + 1) % profiles.size());
    }

    saberState.extention += dt / getCurrentSaberProfile().extensionDuration * saberState.extensionDirection;

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

void activateSaberProfile(int profileIndex)
{
    currentProfileIndex = profileIndex;
}

void addSaberProfile(SaberProfile profile)
{
    profiles.push_back(profile);
}

SaberProfile &getCurrentSaberProfile()
{
    return profiles[currentProfileIndex];
}
