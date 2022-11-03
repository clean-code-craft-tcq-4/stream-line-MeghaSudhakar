
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <stdio.h>
#include "./receiver/receiver.h"

TEST_CASE("maximum value - first value in the readings, expect that same value is returned")
{
    double maxValue = 0.0;
    double newValue = 9.8;
    int instanceNum = 1;
    double expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("maximum value - second value in the readings, expect that max value between last max and new value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.7;
    int instanceNum = 2;
    double expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("maximum value - third value in the readings, expect that max value  between last max and new value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.9;
    int instanceNum = 3;
    double expectedValue = 9.9;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("minimum value - first value in the readings, expect that same value is returned")
{
    double minValue = 0.0;
    double newValue = 9.9;
    int instanceNum = 1;
    double expectedValue = 9.9;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("minimum value - second value in the readings, expect that min value between last min and new value is returned")
{
    double minValue = 9.9;
    double newValue = 9.8;
    int instanceNum = 2;
    double expectedValue = 9.8;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("minimum value - third value in the readings, expect that min value  between last min and new value is returned")
{
    double minValue = 9.8;
    double newValue = 9.7;
    int instanceNum = 3;
    double expectedValue = 9.7;

    getMinValue(&minValue, newValue, instanceNum);
    REQUIRE(minValue == expectedValue);
}

TEST_CASE("simple moving average - with one value, verify that same value is returned")
{
    double value[5];
    double newValue = 9.9;
    int instanceNum = 1;
    double expectedValue = 9.9;

    REQUIRE(getAverageValue(value, newValue, instanceNum) == expectedValue);
}
