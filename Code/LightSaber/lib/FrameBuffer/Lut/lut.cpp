#include "lut.h"

#include <tuple>
#include <const.h>
#include <functional>
#include "color.h"

namespace Lut
{
    // generates a lut from a function
    void generateBWLut(BWLut lut, std::function<Color::Color(Color::Color)> f)
    {
        for (int i = 0; i < 256; i++)
        {
            lut[i] = f(i);
        }
    }

    // combines two luts by applying one to the other
    // This is like a layering adjustment in photoshop
    // vvv top  vvv
    // --- base ---
    void combineLuts(BWLut base, BWLut top)
    {
        for (int i = 0; i < 256; i++)
        {
            base[i] = top[base[i]];
        }
    }

    String lutToString(BWLut lut)
    {
        String s = "";
        for (int i = 0; i < 256; i++)
        {
            s += String(lut[i], DEC) + " ";
        }
        return s;
    }
}
