#include "GenerateChargingParameters.h"

int main()
{
 char ToConsole[2000];
 int NumOfValuesToBeGenerated = 50;
 
 GenerateCurrentTempPairToCsv(ToConsole, NumOfValuesToBeGenerated);
 printf("%s",ToConsole);
 return 0; 
}
