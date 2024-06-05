#include "gyroscope.h"

#include <BMI160Gen.h>
#include <tuple>
#include <genericUtil.h>

Gyroscope::Gyroscope(const int cs_pin, const int int_pin) : bmi160()
{
    bmi160.begin(BMI160GenClass::SPI_MODE, Wire, cs_pin, int_pin);
    // bmi160.getFIFOBytes m;
}

Gyroscope::~Gyroscope()
{
}

void Gyroscope::update()
{
    int rate = bmi160.getGyroRange();
    int rawGx, rawGy, rawGz;
    bmi160.readGyro(rawGx, rawGy, rawGz);

    gx = convertRawGyro(rawGx, rate);
    gy = convertRawGyro(rawGy, rate);
    gz = convertRawGyro(rawGz, rate);

    float dt = (micros() - lastUpdateMicros) / 1000000.0f;
    lastUpdateMicros = micros();

    rx += gx * dt;
    ry += gy * dt;
    rz += gz * dt;
}

float Gyroscope::convertRawGyro(int gRaw, int rate)
{
    float g = (float)(gRaw * rate) / 32768.0;
    return g;
}

void Gyroscope::resetOrientation()
{
    rx, ry, rz = 0;
}

// Fix gyro drift
std::tuple<float, float, float> Gyroscope::getOrientation()
{
    return std::make_tuple(rx, ry, rz);
}

// gets the twist (angular roll speed gy) in deg/s
float Gyroscope::getTwist()
{
    return gy;
}

// gets the combined rotation (saber spin) around the other axies (gx, gz) in deg/s
// it is calculated by adding the two rotation vectors and taking their magnitude
float Gyroscope::getSteve()
{
    // Pythagoras time!!!
    return sqrt((gx * gx) + (gz * gz));
}