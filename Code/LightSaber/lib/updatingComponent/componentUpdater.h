#pragma once

#include "updatingComponent.h"
#include <vector>

class ComponentUpdater
{
    std::vector<IUpdatingComponent *> components;
    ComponentUpdater();
    ~ComponentUpdater() = default;

public:
    static ComponentUpdater &getInstance();
    void updateAll();
    void addComponent(IUpdatingComponent *component);
    void removeComponent(IUpdatingComponent *component);
    std::vector<IUpdatingComponent *> &getComponents();
};