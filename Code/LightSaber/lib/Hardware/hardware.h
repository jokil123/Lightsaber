#pragma once

#include "Pushbutton/pushbutton.h"
#include "LedStrip/ledStrip.h"
#include "Gyroscope/gyroscope.h"

// Singleton class for hardware control
class Hardware : public IUpdatingComponent
{
public:
    static Hardware &getInstance();
    void update();
    PushButton button0;
    PushButton button1;
    LedStrip ledStrip;
    Gyroscope gyroscope;

private:
    // Constructor
    Hardware();
    ~Hardware() = default;
};