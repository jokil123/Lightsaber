#include "pushbuttons.h"

#include <Arduino.h>

void initPushButtons()
{
    pinMode(BUTTON0_PIN, INPUT);
    pinMode(BUTTON1_PIN, INPUT);
}

int getButton0()
{
    return digitalRead(BUTTON0_PIN);
}

int getButton1()
{
    return digitalRead(BUTTON1_PIN);
}