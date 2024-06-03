#include "profileManager.h"

SaberProfile &ProfileManager::getCurrentProfile()
{
    return profiles.at(currentProfileIndex);
}

void ProfileManager::update()
{
    if (Hardware::getInstance().button1.getKeyDown())
    {
        currentProfileIndex = (currentProfileIndex + 1) % profiles.size();
    }
}

void ProfileManager::addProfile(SaberProfile profile)
{
    profiles.push_back(profile);
}