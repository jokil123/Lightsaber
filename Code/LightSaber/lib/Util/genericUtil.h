#pragma once

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

template <typename D>
void serialPlot(const char *label, const D &data)
{
    std::string output = ">" + std::string(label) + ": " + std::to_string(data);
    Serial.println(output.c_str());
}