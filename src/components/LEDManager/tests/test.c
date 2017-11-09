#include <LEDManager.h>
#include <unity.h>

static void createLEDManagerSucceeds(void);

int main()
{
	UNITY_BEGIN();
	RUN_TEST(createLEDManagerSucceeds);
	UNITY_END();
}

void createLEDManagerSucceeds(void)
{
	(void)LEDManager;
	// TODO: Continue testing LEDManager
	/**
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
					&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);

	runScheduler();
	*/
}
