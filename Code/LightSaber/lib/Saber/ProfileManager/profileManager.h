#pragma once

#include "saberProfile.h"

#include <vector>
#include <const.h>
#include <hardware.h>

class ProfileManager
{
    int currentProfileIndex;
    std::vector<SaberProfile> profiles = std::vector<SaberProfile>();

public:
    SaberProfile &getCurrentProfile();
    void update();

    // TODO: Replace with DI
    void addProfile(SaberProfile profile);
};
