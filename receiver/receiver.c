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

double getAverageValue(double * value, double newValue, int instanceNum)
{
    double sum = 0.0;
    int numValuesToProcess;

    if (instanceNum < SIMPLE_MOVING_AVERAGE_BOUNDARY)
    {
        value[instanceNum] = newValue;
        numValuesToProcess = instanceNum;
    }
    else
    {
        value[instanceNum % SIMPLE_MOVING_AVERAGE_BOUNDARY] = newValue;
        numValuesToProcess = SIMPLE_MOVING_AVERAGE_BOUNDARY;
    }
    for (int index = 0; index < numValuesToProcess; ++index)
    {
        sum += value[index];
    }
    return (sum/((double)instanceNum));
}
