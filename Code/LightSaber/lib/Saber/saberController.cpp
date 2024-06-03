#include "saberController.h"

SaberController::SaberController(ProfileManager &profileManager, StateManager &stateManager, SaberRenderer &saberRenderer, SaberSynth &saberSynth) : profileManager(profileManager), stateManager(stateManager), saberRenderer(saberRenderer), saberSynth(saberSynth)
{
    return;
}

void SaberController::update()
{
    profileManager.update();
    SaberProfile &currentProfile = profileManager.getCurrentProfile();

    SaberState &newState = stateManager.update(currentProfile);

    saberRenderer.update(currentProfile, newState);
    saberSynth.synthesize(currentProfile, newState);
}