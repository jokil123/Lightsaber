#include "componentUpdater.h"

#include "updatingComponent.h"

#include <Arduino.h>
#include <vector>
#include <algorithm>

ComponentUpdater::ComponentUpdater() : components()
{
}

ComponentUpdater &ComponentUpdater::getInstance()
{
    static ComponentUpdater instance;
    return instance;
}

void ComponentUpdater::updateAll()
{
    for (IUpdatingComponent *component : components)
    {
        component->update();
    }
}

void ComponentUpdater::addComponent(IUpdatingComponent *component)
{
    components.push_back(component);
}

void ComponentUpdater::removeComponent(IUpdatingComponent *component)
{
    auto it = std::find(components.begin(), components.end(), component);
    if (it != components.end())
    {
        components.erase(it);
    }
}
