//#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <stdio.h>
#include <systemSignals.h>

int main()
{
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
			&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);

	printf("System started\n");
	runScheduler();
	printf("System scheduler finished\n");
	return 0;
}
