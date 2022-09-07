
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

TEST_CASE("To check if charging current is generated")
{
  float RandomData[10];
  float ExpectedData[10] = {0, 0.5, 1.0, 1.5, 2.0, 2.5, 3.0, 3.5, 4.0, 4.5}; // with slope = 0.5 and xIntercept = 0
  int NumOfValuesToBeGenerated = SIZE_OF_ARRAY(RandomData);
  
  GenerateChargingCurrentValues(RandomData, NumOfValuesToBeGenerated);
  
  REQUIRE(memcmp(RandomData, ExpectedData, sizeof(RandomData)) == 0);
}

