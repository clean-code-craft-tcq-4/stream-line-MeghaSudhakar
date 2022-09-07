
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "catch.hpp"
#include <string.h>
#include "GenerateChargingParameters.h"
#include <stdio.h>

TEST_CASE("To test if 10 random values are generated from function GenerateLinearExpValues")
{
  float RandomData[10];
  float ExpectedData[10] = {2, 2.2, 2.4, 2.6, 2.8, 3.0, 3.2, 3.4, 3.6, 3.8}; // with slope = 0.2 and xIntercept = 2
  int NumOfValuesToBeGenerated = SIZE_OF_ARRAY(RandomData);
  linerExpParameters LinearExpressionParam = {0.2, 2.0}; // Slope, xIntercept

  GenerateLinearExpValues(RandomData, LinearExpressionParam, NumOfValuesToBeGenerated);
  
  REQUIRE(memcmp(RandomData, ExpectedData, sizeof(RandomData)) == 0);
}


