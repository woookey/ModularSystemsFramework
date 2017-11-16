#ifndef CP_HA_LED_H
#define CP_HA_LED_H

typedef struct LEDType LEDType_t;
typedef LEDType_t *const CP_HA_LEDStruct;

void CP_HA_LEDConstruct(CP_HA_LEDStruct LEDInstance);
void CP_HA_LEDSwitchOn(CP_HA_LEDStruct LEDInstance);
void CP_HA_LEDSwitchOff(CP_HA_LEDStruct LEDInstance);

#endif
