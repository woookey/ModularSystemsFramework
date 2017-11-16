#include <CP_HA_LED.h>
#include <LEDType.h>
#include <stdlib.h>

#define CPU_ACTIVITY_LED_PORT 1
#define POWER_ON_INDICATION_LED_PORT 2
#define EXECUTING_INDICATION_LED_PORT 3
#define SAFETY_STOP_INDICATION_LED_PORT 4

struct LEDType CPUActivityLEDInstance = { CPU_ACTIVITY_LED_PORT };
struct LEDType powerOnIndicationLEDInstance = { POWER_ON_INDICATION_LED_PORT };
struct LEDType executingIndicationLEDInstance = { EXECUTING_INDICATION_LED_PORT };
struct LEDType safetyStopIndicationLEDInstance = { SAFETY_STOP_INDICATION_LED_PORT };

CPUActivityLED = &CPUActivityLEDInstance;
powerOnIndicationLED = &powerOnIndicationLEDInstance;
executingIndicationLED = &executingIndicationLEDInstance;
safetyStopIndicationLED = &safetyStopIndicationLEDInstance;

void CP_HA_LEDConstruct(CP_HA_LEDStruct LEDInstance)
{
	printf("LED connected to port %d constructed\n", LEDInstance->pin);
}

void CP_HA_LEDSwitchOn(CP_HA_LEDStruct LEDInstance)
{
	printf("LED connected to port %d switched on\n", LEDInstance->pin);
}

void CP_HA_LEDSwitchOff(CP_HA_LEDStruct LEDInstance)
{
	printf("LED connected to port %d switched off\n", LEDInstance->pin);
}
