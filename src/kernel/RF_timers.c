#include <RF_timers.h>
#include <RF_definitions.h>
#include <assert.h>
#include <stddef.h>
#include <string.h>

/**
 * TODO: There needs to be an array with pointers to all constructed
 * timers so that on sysTick all timers get updated
 */
static struct
{
	RF_Timer* registeredTimers[RF_MAX_NUMBER_OF_TIMERS];
	uint16_t noOfRegisteredTimers;
} RFRegisteredTimers = {{NULL}, 0};

static bool add_timer(RF_Timer* timerPtr);
#define REGISTER_TIMER(timer) add_timer(timer)

void RFTimerConstructor(RFAgent* agentSubscribed, RF_Timer* timer, uint32_t signal)
{
	assert(agentSubscribed != NULL);
	assert(timer != NULL);
	assert(signal > 0 && signal < RF_MAX_NUMBER_OF_SIGNALS);
	memset(timer, 0, sizeof(RF_Timer));

	timer->agent = agentSubscribed;

	timer->baseEvt.eventSize = sizeof(RFEvent);
	timer->baseEvt.pendingConsumers = 0;
	timer->baseEvt.signalValue = signal;

	timer->isArmed = false;
	timer->ticks = 0;
	assert(REGISTER_TIMER(timer));
}

/**
 * Arms the timer to a specified timeout in construction
 */
void RFTimer_armTimer(RF_Timer *timer, uint32_t timeoutInTicks)
{
	assert(timer != NULL);
	assert(timeoutInTicks > 0);
	timer->ticks = timeoutInTicks;
}

/**
 * Disarms the timer
 */
void RFTimer_disarmTimer(RF_Timer *timer);

bool add_timer(RF_Timer* timerPtr)
{
	if ((RFRegisteredTimers.registeredTimers[RFRegisteredTimers.noOfRegisteredTimers] == NULL)
			&& (RFRegisteredTimers.noOfRegisteredTimers < RF_MAX_NUMBER_OF_TIMERS))
	{
		RFRegisteredTimers.registeredTimers[RFRegisteredTimers.noOfRegisteredTimers] = timerPtr;
		RFRegisteredTimers.noOfRegisteredTimers++;
		return true;
	}
	return false;
}
