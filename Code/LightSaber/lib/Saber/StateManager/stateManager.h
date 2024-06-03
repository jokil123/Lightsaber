#pragma once

#include <updatingComponent.h>
#include <ProfileManager/profileManager.h>

#include "saberState.h"

class StateManager
{
    ulong lastUpdateTime;
    SaberState saberState;

public:
    SaberState &update(SaberProfile &profile);
};
