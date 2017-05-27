/**
 * LED Manager flashes the LEDs connected to the STM32 microcontroller.
 * It indicates communication link and ping
 */
#ifndef HW_LED_MANAGER_TEST_H
#define HW_LED_MANAGER_TEST_H

#include <RF_agents.h>

extern RFAgent *const HW_RF_LEDManagerTest;

/**
 * Constructs LED Manager
 */
void HW_RF_LEDManagerTestConstructor(RFAgent *const self);

#endif
