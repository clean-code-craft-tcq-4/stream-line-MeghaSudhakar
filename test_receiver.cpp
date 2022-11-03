
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <stdio.h>
#include "./receiver/receiver.h"

TEST_CASE("maximum value - first value in the readings, expect that same value is returned")
{
    double maxValue = 0.0;
    double newValue = 9.8;
    int instanceNum = 0;
    double expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("maximum value - second value in the readings, expect that max value between last max and new value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.7;
    int instanceNum = 1;
    double expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("maximum value - third value in the readings, expect that max value  between last max and new value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.9;
    int instanceNum = 2;
    double expectedValue = 9.9;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("minimum value - first value in the readings, expect that same value is returned")
{
    double minValue = 0.0;
    double newValue = 9.9;
    int instanceNum = 0;
    double expectedValue = 9.9;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("minimum value - second value in the readings, expect that min value between last min and new value is returned")
{
    double minValue = 9.9;
    double newValue = 9.8;
    int instanceNum = 1;
    double expectedValue = 9.8;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("minimum value - third value in the readings, expect that min value between last min and new value is returned")
{
    double minValue = 9.8;
    double newValue = 9.7;
    int instanceNum = 2;
    double expectedValue = 9.7;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("simple moving average - with one streamed value, verify that same value is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.9;
    int instanceNum = 0;
    double expectedValue = 9.9;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}

TEST_CASE("simple moving average - with two streamed values, verify that average of two values is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.2;
    int instanceNum = 1;
    double expectedValue = 9.55;

    value[0] = 9.9;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}

TEST_CASE("simple moving average - with three streamed values, verify that average of three values is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.7;
    int instanceNum = 2;
    double expectedValue = 9.8;

    value[0] = 9.9;
    value[1] = 9.8;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}

TEST_CASE("simple moving average - with four streamed values, verify that average of four values is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.6;
    int instanceNum = 3;
    double expectedValue = 9.75;

    value[0] = 9.9;
    value[1] = 9.8;
    value[2] = 9.7;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}

TEST_CASE("simple moving average - with five streamed values, verify that average of five values is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.5;
    int instanceNum = 4;
    double expectedValue = 9.7;

    value[0] = 9.9;
    value[1] = 9.8;
    value[2] = 9.7;
    value[3] = 9.6;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}

TEST_CASE("simple moving average - with more than five streamed values, verify that average of last five values is returned")
{
    double value[SIMPLE_MOVING_AVERAGE_BOUNDARY];
    double newValue = 9.4;
    int instanceNum = 5;
    double expectedValue = 9.6;

    value[0] = 9.9;
    value[1] = 9.8;
    value[2] = 9.7;
    value[3] = 9.6;
    value[4] = 9.5;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}
