#include <stdio.h>
#include "receiver.h"

void getMaxValue(float *maxValue, float newValue, int instanceNum)
{
    if (instanceNum == 1)
    {
        *maxValue = newValue;
    }
    if (*maxValue < newValue)
    {
        *maxValue = newValue;
    }
}
