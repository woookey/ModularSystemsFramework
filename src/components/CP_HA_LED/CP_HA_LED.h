#ifndef CP_HA_LED_H
#define CP_HA_LED_H

#include <LEDType.h>

typedef struct LEDType LEDType_t;
typedef LEDType_t *const CP_HA_LEDStruct;

CP_HA_LEDStruct CPUActivityLED;

CP_HA_LEDStruct powerOnIndicationLED;
CP_HA_LEDStruct executingIndicationLED;
CP_HA_LEDStruct safetyStopIndicationLED;

void CP_HA_LEDConstruct(CP_HA_LEDStruct LEDInstance);
void CP_HA_LEDSwitchOn(CP_HA_LEDStruct LEDInstance);
void CP_HA_LEDSwitchOff(CP_HA_LEDStruct LEDInstance);

#endif
