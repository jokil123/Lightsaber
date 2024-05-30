#include "color.h"

#include "const.h"

#include <Arduino.h>

// This is a simple function that adds two Color objects together.
// It will add the color values of a and b together, and return the result.
// Values will be clamped to 0xFF per channel (This prevents overflow into another color channel).
Color colorAdd(Color a, Color b)
{
    uint8_t rC = min((a >> 16 & 0xFF) + (b >> 16 & 0xFF), (Color)0xFF);
    uint8_t gC = min((a >> 8 & 0xFF) + (b >> 8 & 0xFF), (Color)0xFF);
    uint8_t bC = min((a & 0xFF) + (b & 0xFF), (Color)0xFF);
    return (rC << 16) | (gC << 8) | bC;
}

// This is a simple function that multiplies a Color with another Color per channel (Essentially multiply blending).
// it first needs to normalize the color values to a float between 0 and 1.
// It will multiply the color values of a and b together, and return the result.
Color colorMultiply(Color a, u_int32_t b)
{
    float rA = (a >> 16 & 0xFF) / 255.0;
    float gA = (a >> 8 & 0xFF) / 255.0;
    float bA = (a & 0xFF) / 255.0;

    float rB = (b >> 16 & 0xFF) / 255.0;
    float gB = (b >> 8 & 0xFF) / 255.0;
    float bB = (b & 0xFF) / 255.0;

    uint8_t rC = min((Color)((rA * rB) * 255.0), (Color)0xFF);
    uint8_t gC = min((Color)((gA * gB) * 255.0), (Color)0xFF);
    uint8_t bC = min((Color)((bA * bB) * 255.0), (Color)0xFF);

    return (rC << 16) | (gC << 8) | bC;
}

Color colorMultiplyScalar(Color c, float s)
{
    uint8_t s8 = static_cast<uint8_t>(floor(s * 255));

    Color scalarColor = (s8 << 16) | (s8 << 8) | s8;

    return colorMultiply(c, scalarColor);
}

Color gammaCorrect(Color c, float gamma)
{
    float r = pow((c >> 16 & 0xFF) / 255.0, gamma) * 255;
    float g = pow((c >> 8 & 0xFF) / 255.0, gamma) * 255;
    float b = pow((c & 0xFF) / 255.0, gamma) * 255;

    return ((uint8_t)r << 16) | ((uint8_t)g << 8) | (uint8_t)b;
}

Color fromFloatColor(FloatColor c)
{
    uint8_t r = static_cast<uint8_t>(c * 255);
    uint8_t g = static_cast<uint8_t>(c * 255);
    uint8_t b = static_cast<uint8_t>(c * 255);

    return (r << 16) | (g << 8) | b;
}

FloatColor toFloatColor(Color c)
{
    return (c >> 16 & 0xFF) / 255.0;
}

// This function applies a brightness adjustment to a color.
// It takes a color and a brightness value, and returns the color with the adjusted brightness.
Color applyBrightness(Color color, uint8_t brightness)
{
    // Extract individual color components (red, green, blue)
    uint8_t red = (color >> 16) & 0xFF;
    uint8_t green = (color >> 8) & 0xFF;
    uint8_t blue = color & 0xFF;

    // Calculate the average brightness of the color
    uint8_t originalBrightness = (red + green + blue) / 3;

    if (originalBrightness == 0)
    {
        return 0;
    }

    // Scale the color components based on the adjusted brightness
    red = (red * brightness) / originalBrightness;
    green = (green * brightness) / originalBrightness;
    blue = (blue * brightness) / originalBrightness;

    // Combine the adjusted components back into a single uint32_t color
    return (static_cast<uint32_t>(red) << 16) | (static_cast<uint32_t>(green) << 8) | blue;
}