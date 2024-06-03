#include "pushbutton.h"

#include <Arduino.h>
#include <updatingComponent.h>

PushButton::PushButton(int pin)
{
    this->pin = pin;
    pinMode(pin, INPUT);
}

void PushButton::update()
{
    lastState = currentState;
    currentState = digitalRead(pin);
}

const bool PushButton::getKey()
{
    return currentState;
}

const bool PushButton::getKeyDown()
{
    return currentState && !lastState;
}

const bool PushButton::getKeyUp()
{
    return !currentState && lastState;
}
