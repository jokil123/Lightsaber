#include "saberRenderer.h"
#include <ProfileManager/saberProfile.h>
#include <StateManager/stateManager.h>

void SaberRenderer::update(SaberProfile &profile, SaberState &state)
{
    if (micros() - lastFrameAt > 1000000.0f / FRAME_RATE)
    {
        // Serial.print(">Time since last frame:");
        // Serial.println(micros() - lastFrameAt);

        lastFrameAt = micros();

        // Serial.print(">Extension:");
        // Serial.println(state.extention);
        render(profile, state);
    }
}

void SaberRenderer::render(SaberProfile &profile, SaberState &state)
{
    frameBuffer.clear();

    frameBuffer.fillPartial(profile.baseColor, 1, 1 - state.extention / 2);
    frameBuffer.fillPartial(profile.baseColor, 0, state.extention / 2);

    Hardware::getInstance().ledStrip.blitStrip(frameBuffer);
}