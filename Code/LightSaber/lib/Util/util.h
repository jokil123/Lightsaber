// util.h
#ifndef UTIL_H
#define UTIL_H

#include <const.h>

// Function declarations
template <typename T>
int sign(T val);

template <typename T>
int clamp(T val, T min, T max);

void printFrameBuffer(FrameBuffer frameBuffer);

String colorToStringCompact(Color color);

#endif // UTIL_H