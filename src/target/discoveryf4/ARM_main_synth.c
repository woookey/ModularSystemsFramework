#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <stdio.h>

int main()
{
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
			&LEDManagerPool[0], sizeof(RFEvent)*10);

	printf("Agent started\n");
	runScheduler();
	printf("After scheduler ran\n");
	return 0;
}
