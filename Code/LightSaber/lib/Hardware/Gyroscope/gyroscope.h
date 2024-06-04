#pragma once

#include <BMI160Gen.h>
#include <updatingComponent.h>

class Gyroscope : public IUpdatingComponent
{
    BMI160GenClass bmi160;
    float gx, gy, gz;

public:
    Gyroscope(const int spi_cs_pin, const int intr_pin);
    ~Gyroscope();
    void update();

    static float convertRawGyro(int gRaw, int rate);

    float getTwist();
    float getSteve();
};