#include <LEDManager.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <systemSignals.h>
#include <unity.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
	bool isOn;
	uint32_t timesSwitchedOn;
	uint32_t timesSwitchedOff;
} LED;
LED LEDInstance = {false, 0, 0};

static void resetVariables(void)
{
	memset(&LEDInstance, 0, sizeof(LED));
	LEDInstance.isOn = false;
	LEDInstance.timesSwitchedOff = 0;
	LEDInstance.timesSwitchedOn = 0;
}

void CP_HD_LED_switchLEDOff()
{
	LEDInstance.isOn = false;
	LEDInstance.timesSwitchedOff++;
}

void CP_HD_LED_switchLEDOn()
{
	LEDInstance.isOn = true;
	LEDInstance.timesSwitchedOn++;
}

void accelerateTimeByNTicks(uint32_t nTicks)
{
	uint32_t i;
	for (i = 0; i < nTicks; i++)
	{
		RFTimer_decreaseTimersByOneTick();
		runScheduler();
	}
}

static void createLEDManagerSucceeds(void);

int main()
{
	UNITY_BEGIN();
	RUN_TEST(createLEDManagerSucceeds);
	UNITY_END();
}

void createLEDManagerSucceeds(void)
{
	resetVariables();
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
					&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);
	TEST_ASSERT(LEDManager->currentHandler != NULL);
	runScheduler();
	TEST_ASSERT(LEDInstance.isOn);
	TEST_ASSERT(LEDInstance.timesSwitchedOn == (uint32_t)1);
	accelerateTimeByNTicks(500);
	TEST_ASSERT(!LEDInstance.isOn)
	TEST_ASSERT(LEDInstance.timesSwitchedOn == (uint32_t)1);
	TEST_ASSERT(LEDInstance.timesSwitchedOff == (uint32_t)1);
	accelerateTimeByNTicks(500);
	TEST_ASSERT(LEDInstance.isOn);
	TEST_ASSERT(LEDInstance.timesSwitchedOn == (uint32_t)2);
	TEST_ASSERT(LEDInstance.timesSwitchedOff == (uint32_t)1);
}
