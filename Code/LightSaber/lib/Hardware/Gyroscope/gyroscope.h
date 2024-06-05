#pragma once

#include <BMI160Gen.h>
#include <updatingComponent.h>
#include <tuple>

class Gyroscope : public IUpdatingComponent
{
    BMI160GenClass bmi160;
    // acceleration along the different axies
    float gx, gy, gz;
    int lastUpdateMicros;

    // orientation along the different axies
    float rx, ry, rz;

    static float convertRawGyro(int gRaw, int rate);

public:
    Gyroscope(const int spi_cs_pin, const int intr_pin);
    ~Gyroscope();
    void update();

    void resetOrientation(); // Resets the orientation back to 0, 0, 0
    std::tuple<float, float, float> getOrientation();

    float getTwist();
    float getSteve();
};