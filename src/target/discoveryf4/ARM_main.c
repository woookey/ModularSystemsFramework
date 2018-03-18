#include <LEDManager.h>
#include <CP_HA_HardwareSetup.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <RF_timers.h>
#include <systemSignals.h>
#include <stdbool.h>

int main()
{
	setupHardware();
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();


	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
						&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);
	startHardware();
	/**
	 * TODO: Investigate if there should be a lock for starting the framework
	 * before all agents are initialised - just before while loop
	 */
	return 0;
}
