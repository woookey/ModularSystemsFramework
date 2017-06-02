#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <systemSignals.h>

static void setupHardware(void);

int main()
{
	setupHardware();
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
	#define PIN7 7
	#define LED_ORANGE 13

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	GPIOC->MODER |= (1 << (PIN7 << 1));
	GPIOC->OSPEEDR |= (3 << (PIN7 << 1));
	GPIOC->BSRR |= (1 << PIN7);

	GPIOD->MODER |= (1 << (LED_ORANGE << 1));
	GPIOD->OSPEEDR |= (3 << (LED_ORANGE << 1));
	GPIOD->BSRR |= (1 << LED_ORANGE);
}
