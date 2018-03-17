//#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <RF_timers.h>
#include <stdio.h>
#include <systemSignals.h>
#include <time.h>
#include <stdbool.h>
#include <CP_HA_HardwareSetup.h>

#define MS_PER_SEC 1000

int main()
{
	setupHardware();
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();


	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
							&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);

	// Initiate synthetic timing
	clock_t t;
	t = clock();
	/**
	 * Run scheduler and decrease timers every 1ms
	 */
	while(true)
	{
		if ((float)(clock()-t)/((float)CLOCKS_PER_SEC/(float)MS_PER_SEC) >= (float)1)
		{
			RFTimer_decreaseTimersByOneTick();
			t = clock();
		}
		runScheduler();
	}
	return 0;
}
