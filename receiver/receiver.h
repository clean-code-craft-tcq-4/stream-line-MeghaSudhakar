#ifndef RECEIVER_H
#define RECEIVER_H

#define SIMPLE_MOVING_AVERAGE_BOUNDARY 5

void getMaxValue(double *maxValue, double newValue, int instanceNum);
void getMinValue(double * minValue, double newValue, int instanceNum);
double getAverageValue(double * value, double newValue, int instanceNum);

#endif //RECEIVER_H
