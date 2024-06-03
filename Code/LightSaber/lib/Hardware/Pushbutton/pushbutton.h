#pragma once

#include <Arduino.h>
#include <updatingComponent.h>

// This class manages a push button
class PushButton : public IUpdatingComponent
{
    int pin;
    int currentState;
    int lastState;

public:
    // Constructor
    PushButton(int pin);

    // Returns the state of the button
    void update();

    // Returns true if the button is currently pressed
    const bool getKey();

    // Returns true if the button was pressed since the last update
    const bool getKeyDown();

    // Returns true if the button was released since the last update
    const bool getKeyUp();
};