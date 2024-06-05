#include "util.h"

#include <Arduino.h>

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
