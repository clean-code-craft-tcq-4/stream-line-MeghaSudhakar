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

void getMinValue(double * minValue, double newValue, int instanceNum)
{
    if (instanceNum == 1)
    {
        *minValue = newValue;
    }
    else
    {
        if (*minValue > newValue)
        {
            *minValue = newValue;
        }
    }
}
