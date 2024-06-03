#pragma once

#include <const.h>
#include <functional>
#include <color.h>

namespace Lut
{
    typedef uint8_t BWLut[256];

    void generateBWLut(BWLut lut, std::function<Color::Color(Color::Color)> f);

    void combineLuts(BWLut base, BWLut top);

    String lutToString(BWLut lut);
}
