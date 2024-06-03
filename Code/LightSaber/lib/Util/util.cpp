#include "util.h"

#include <Arduino.h>

template <typename T>
int sign(T val)
{
    return (T(0) < val) - (val < T(0));
}

template <typename T>
int clamp(T val, T min, T max)
{
    return val < min ? min : (val > max ? max : val);
}

// free RAM check for debugging. SRAM for ATmega328p = 2048Kb.
int availableMemory()
{
    // Use 1024 with ATmega168
    int size = 2048;
    byte *buf;
    while ((buf = (byte *)malloc(--size)) == NULL)
        ;
    free(buf);
    return size;
}