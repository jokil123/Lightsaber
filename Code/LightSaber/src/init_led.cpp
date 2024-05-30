#include "init_led.h"

#include <Arduino.h>
#include "const.h"

// blinks the led on the board
void init_led()
{
    pinMode(LED_BUILTIN_PIN, OUTPUT);
    digitalWrite(LED_BUILTIN_PIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN_PIN, LOW);
    delay(100);
    digitalWrite(LED_BUILTIN_PIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN_PIN, LOW);
}