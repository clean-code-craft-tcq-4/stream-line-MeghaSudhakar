
#pragma once
#include <math.h>
#include <string.h>
#include <stdio.h>

#define ROUND_OFF_TO_2_DECIMAL(Num)   (floor((Num)*100)/100)
#define SIZE_OF_ARRAY(array)  (sizeof(array)/sizeof(array[0]))

typedef struct{
  float slope;
  float xIntercept;
}linerExpParameters;
