#pragma once

#include "Pushbutton/pushbutton.h"
#include "LedStrip/ledStrip.h"

// Singleton class for hardware control
class Hardware : public IUpdatingComponent
{
public:
    static Hardware &getInstance();
    void update();
    PushButton button0;
    PushButton button1;
    LedStrip ledStrip;

private:
    // Constructor
    Hardware();
    ~Hardware() = default;
};