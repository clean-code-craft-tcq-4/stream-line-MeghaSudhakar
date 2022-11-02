
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <stdio.h>
#include "receiver.h"

TEST_CASE("maximum value - first value in the readings, expect that same value is returned")
{
    float maxValue = 0.0;
    float newValue = 9.8;
    int instanceNum = 1;
    float expectedValue = 9.8;

    getMaxValue(&maxValue, newValue, instanceNum);
    REQUIRE(maxValue = expectedValue);
}
