#pragma once

#include <ProfileManager/saberProfile.h>
#include <StateManager/saberState.h>

class SaberSynth
{
public:
    void synthesize(SaberProfile &profile, SaberState &state);
};