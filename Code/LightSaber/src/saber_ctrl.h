#pragma once

#include <memory>
struct SaberState
{
    float extention;        // 0 - 1
    int extensionDirection; // -1: retracting, 0: stopped, 1: extending
};

// Call this function to update the saber state
void updateSaberState(float dt);

SaberState &getSaberState();