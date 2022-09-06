#pragma once
#include <math.h>
#include <string.h>
#include <stdio.h>

void GenerateCurrentTemperaturePairToCsv(char* ToConsole, int NumOfValuesToBeGenerated)
{
  //char Tempchar[50] = "Current in A, Temperature in degC\n";
  char Tempchar[50] = {0};
  int Loop;
  float CurrentArray[NumOfValuesToBeGenerated];
  float TemperatureArray[NumOfValuesToBeGenerated];
  
  GenerateChargingCurrentValues(CurrentArray, NumOfValuesToBeGenerated);
  GenerateBatteryTemperatureValues(TemperatureArray, NumOfValuesToBeGenerated);
  
  //strcat(ToConsole, Tempchar); // copy the header first
  for(Loop = 0; Loop < NumOfValuesToBeGenerated;Loop++)
  {
    sprintf(Tempchar, "%0.2f, %0.2f\n",TemperatureArray[Loop],CurrentArray[Loop]);
    //Data is sent to stdout buffer
    //printf(ToConsole, " Temperature: %.2f, Charge Rate: %.2f\n", TemperatureArray[Loop], CurrentArray[Loop]);
    strcat(ToConsole, Tempchar);
  }
}
