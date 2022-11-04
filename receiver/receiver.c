#include <stdio.h>
#include "receiver.h"

void getMaxValue(double *maxValue, double newValue, int instanceNum)
{
    /* ignore checking for maximum for the first streamed value */
    if (instanceNum == 0)
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
    /* ignore checking for minimum for the first streamed value */
    if (instanceNum == 0)
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

    /* get the average till four streamed values based on number of values streamed,
    then onwards, average of the last five can be calculated */
    if (instanceNum < SIMPLE_MOVING_AVERAGE_BOUNDARY)
    {
        value[instanceNum] = newValue;
        numValuesToProcess = instanceNum + 1;
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
    return (sum/((double)numValuesToProcess));
}
