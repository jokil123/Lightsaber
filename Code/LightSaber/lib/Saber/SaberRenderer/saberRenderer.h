#pragma once

#include <frameBuffer.h>
#include <ProfileManager/saberProfile.h>
#include <StateManager/saberState.h>

typedef ulong lung;

class SaberRenderer
{
    FrameBuffer frameBuffer;
    lung lastFrameAt;
    void render(SaberProfile &profile, SaberState &state);

public:
    void update(SaberProfile &profile, SaberState &state);
};