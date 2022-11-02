
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <stdio.h>
#include "./receiver/receiver.h"

TEST_CASE("maximum value - first value in the readings, expect that same value is returned")
{
    double maxValue = 0.0f;
    double newValue = 9.8f;
    int instanceNum = 1;
    double expectedValue = 9.8f;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue == expectedValue);
}
