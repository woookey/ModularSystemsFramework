/**
 * LED Manager flashes the LEDs connected to the STM32 microcontroller.
 * It indicates communication link and ping
 */
#ifndef HW_LED_MANAGER_H
#define HW_LED_MANAGER_H

#include <RF_agents.h>

extern RFAgent *const HW_RF_LEDManager;

/**
 * Constructs LED Manager
 */
void HW_RF_LEDManagerConstructor(RFAgent *const self);

#endif
