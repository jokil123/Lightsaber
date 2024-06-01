#pragma once

#include <memory>
#include <const.h>
struct SaberState
{
    float extention;        // 0 - 1
    int extensionDirection; // -1: retracting, 0: stopped, 1: extending
};

// This struct is used to define the saber profile
// A saber profile is a set of parameters that define the behavior of the saber
// Each character would have a different saber profile for example
struct SaberProfile
{
    float extensionDuration;
    Color baseColor;
};

// Call this function to update the saber state
void updateSaberState(float dt);
SaberState &getSaberState();

void activateSaberProfile(int profileIndex);
void addSaberProfile(SaberProfile profile);
SaberProfile &getCurrentSaberProfile();