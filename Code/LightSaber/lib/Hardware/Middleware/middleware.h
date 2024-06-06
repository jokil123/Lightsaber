#pragma once

#include <Middleware/TwistActivator/twistActivator.h>
#include <hardware.h>

class Middleware : public IUpdatingComponent
{
public:
    TwistActivator twistActivator;

    static Middleware &getInstance();
    Middleware(Hardware &hw);

    void update();
};