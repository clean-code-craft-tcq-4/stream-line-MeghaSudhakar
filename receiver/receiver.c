#include <stdio.h>
#include "receiver.h"

void getMaxValue(double *maxValue, double newValue, int instanceNum)
{
    if (instanceNum == 1)
    {
        *maxValue = newValue;
    }
    else
    {
        if (*maxValue < newValue)
        {
            *maxValue = newValue;
        }
    }
}
