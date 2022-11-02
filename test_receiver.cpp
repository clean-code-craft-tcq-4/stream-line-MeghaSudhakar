
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

TEST_CASE("maximum value - second value in the readings, expect that max value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.7;
    int instanceNum = 2;
    double expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}

TEST_CASE("maximum value - third value in the readings, expect that max value is returned")
{
    double maxValue = 9.8;
    double newValue = 9.9;
    int instanceNum = 3;
    double expectedValue = 9.9;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}
