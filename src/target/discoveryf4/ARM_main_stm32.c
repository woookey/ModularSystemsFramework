#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <systemSignals.h>
#include <stdint.h>

#define PIN7 7
#define LED_ORANGE 13

static void dumbDelay(uint32_t tickCounts);
static void setupHardware(void);
static void switchOrangeOn(void);
static void switchOrangeOff(void);

int main()
{
	setupHardware();
	while (1)
	{
		switchOrangeOn();
		dumbDelay(16800000);
		switchOrangeOff();
		dumbDelay(16800000);
	}


	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
			&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);

	runScheduler();
	return 0;
}

void setupHardware(void)
{
	SystemCoreClockUpdate();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	GPIOC->MODER |= (1 << (PIN7 << 1));
	GPIOC->OSPEEDR |= (3 << (PIN7 << 1));
	GPIOC->BSRR |= (1 << PIN7);

	GPIOD->MODER |= (1 << (LED_ORANGE << 1));
	GPIOD->OSPEEDR |= (3 << (LED_ORANGE << 1));
}

static void dumbDelay(uint32_t tickCounts)
{
	while(tickCounts--) {}
}

static void switchOrangeOn(void) {GPIOD->BSRR |= (1 << LED_ORANGE);}
static void switchOrangeOff(void) {GPIOD->BSRR &= (0 << LED_ORANGE);}
