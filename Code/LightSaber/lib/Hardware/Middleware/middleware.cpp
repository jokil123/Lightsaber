#include "middleware.h"

Middleware::Middleware(Hardware &hw) : twistActivator(hw.gyroscope, 1000, 0.5)
{
}

Middleware &Middleware::getInstance()
{
    // Forgive me god for I have sinned
    // idk might not actually be a sin but feels wrong
    // TODO: Review this
    static Middleware instance = Middleware(Hardware::getInstance());
    return instance;
}

void Middleware::update()
{
    twistActivator.update();
}