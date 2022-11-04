#include <stdio.h>
#include <string.h>
#include "receiver.h"

#define NUM_READINGS    50
#define NUM_SENSORS     2
#define NUM_VALUES      5

int main(void)
{
    double newReading[NUM_SENSORS];
    double sMaxValue[NUM_SENSORS];
    double sMinValue[NUM_SENSORS];
    double sAvgValue[NUM_SENSORS];
    double sLastStreamedValues[NUM_SENSORS][NUM_VALUES];
    char sInfo[NUM_SENSORS][60];

    for (int readingInstance = 0; readingInstance < NUM_READINGS; ++readingInstance)
    {
        scanf("%lf, %lf\n", &newReading[0], &newReading[1]);

        for (int sensor = 0; sensor < NUM_SENSORS; ++sensor)
        {
            getMaxValue(&sMaxValue[sensor], newReading[sensor], readingInstance);
            getMinValue(&sMinValue[sensor], newReading[sensor], readingInstance);
            sAvgValue[sensor] = getAverageValue(&sLastStreamedValues[sensor][0], newReading[sensor], readingInstance);
            sprintf(&sInfo[sensor][0], "Sensor%d: Max-%lf, Min-%lf, Avg-%lf; ", sensor, sMaxValue[sensor], sMinValue[sensor], sAvgValue[sensor]);
        }
        printf("%s\n", strcat(&sInfo[0][0], &sInfo[1][0]));
    }
}
