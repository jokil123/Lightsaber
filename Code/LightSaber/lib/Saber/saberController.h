#pragma once

#include <const.h>
#include <memory>
#include <updatingComponent.h>
#include <vector>
#include "ProfileManager/profileManager.h"
#include "StateManager/stateManager.h"
#include "SaberSynth/saberSynth.h"
#include "SaberRenderer/saberRenderer.h"

// The base class for the saber, this is responsible for managing the saber and components
class SaberController : public IUpdatingComponent
{
    ProfileManager &profileManager;
    StateManager &stateManager;
    SaberRenderer &saberRenderer;
    SaberSynth &saberSynth;

public:
    SaberController(ProfileManager &profileManager, StateManager &stateManager, SaberRenderer &saberRenderer, SaberSynth &saberSynth);
    void update();
};
