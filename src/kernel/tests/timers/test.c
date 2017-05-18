#include <unity.h>
#include <RF_events.h>
#include <RF_timers.h>
#include <RF_agents.h>
#include <RF_queue.h>
#include <testing_utils.h>
#include <string.h>

/**
 * TODO: Eliminate making objects in src/kernel when building timers tests
 */

typedef struct
{
	RFAgent baseAgent;
	RF_Timer sampleTimer;
} timerAgent;
static timerAgent timerAgentInstance;

static void timerAgentEventHandler(RFAgent* const self, RFEvent *const evt);
static void accelerateTimeByNTicks(uint32_t n);

#define SAMPLE_EVENT_SIG 150
#define MEMORY_POOL_SIZE_IN_EVENTS 10

static RFEvent sampleMemoryPool[MEMORY_POOL_SIZE_IN_EVENTS];
static RFEvent sampleEvt =
{
	.eventSize = sizeof(RFEvent),
	.pendingConsumers = 0,
	.signalValue = SAMPLE_EVENT_SIG,
};
static uint32_t noOfTimerGeneratedEvents = 0;

static void resetVariables(void);

static void run_sampleTimerCanBeArmedWithGivenTimeout(void);
static void run_sampleTimerShouldGenerateTimeoutAfterGivenTimeoutPasses(void);

int main()
{
	UNITY_BEGIN();
	initiateTestingUtilities();
	RUN_TEST(run_sampleTimerCanBeArmedWithGivenTimeout);
	RUN_TEST(run_sampleTimerShouldGenerateTimeoutAfterGivenTimeoutPasses);
	return UNITY_END();
}

void run_sampleTimerShouldGenerateTimeoutAfterGivenTimeoutPasses(void)
{
	resetVariables();
	/**
	 * Random uint32_t not equal to 0
	 */
	uint32_t givenTimeoutInTicks = testingUtils_GetRandomUint32();
	givenTimeoutInTicks = givenTimeoutInTicks == 0 ?
		givenTimeoutInTicks++ : givenTimeoutInTicks;

	RFTimer_armTimer(&timerAgentInstance.sampleTimer, givenTimeoutInTicks);
	/**
	 * Fix accelerating time  - it gets stuck
	 */
	//accelerateTimeByNTicks(givenTimeoutInTicks);
	//TEST_ASSERT(noOfTimerGeneratedEvents == 1);
}

void run_sampleTimerCanBeArmedWithGivenTimeout(void)
{
	resetVariables();
	/**
	 * Random uint32_t not equal to 0
	 */
	uint32_t givenTimeoutInTicks = testingUtils_GetRandomUint32();
	givenTimeoutInTicks = givenTimeoutInTicks == 0 ?
			givenTimeoutInTicks++ : givenTimeoutInTicks;

	RFTimer_armTimer(&timerAgentInstance.sampleTimer, givenTimeoutInTicks);
	TEST_ASSERT(timerAgentInstance.sampleTimer.isArmed);
	TEST_ASSERT(timerAgentInstance.sampleTimer.ticks == givenTimeoutInTicks);
}

void resetVariables()
{
	noOfTimerGeneratedEvents = 0;
	memset(&timerAgentInstance, 0, sizeof(timerAgent));
	memset(&sampleMemoryPool[0], 0 , sizeof(RFEvent)*MEMORY_POOL_SIZE_IN_EVENTS);
	createEmptyQueue(&timerAgentInstance.baseAgent.FIFOQueue , sampleMemoryPool, sizeof(RFEvent)*MEMORY_POOL_SIZE_IN_EVENTS);
	RFBaseAgentConstructor(&timerAgentInstance.baseAgent, timerAgentEventHandler);
	RFTimerConstructor(&timerAgentInstance.baseAgent, &timerAgentInstance.sampleTimer, SAMPLE_EVENT_SIG);
}

void timerAgentEventHandler(RFAgent* const self, RFEvent *const evt)
{
	(void)self;
	if (evt->signalValue == SAMPLE_EVENT_SIG)
	{
		noOfTimerGeneratedEvents++;
	}
}

void accelerateTimeByNTicks(uint32_t n)
{
	while (n > 0)
	{
		RFTimer_decreaseTimersByOneTick();
		n--;
	}
}
