#include <LEDManager.h>
#include <CP_HD_LEDDriver.h>
#include <RF_timers.h>
#include <systemSignals.h>
#include <assert.h>

typedef struct
{
	RFAgent baseAgent;
	RF_Timer flashingPeriodTimer;
} LEDManagerAgent;

typedef enum
{
	LED_MANAGER_FLASHING_TIMEOUT_SIGNAL = SS_END_OF_SIGNAL_SPACE,
} PrivateSignals;

typedef enum
{
	LED_MANAGER_FLASHING_TIMEOUT_IN_MS = 500,
} PrivateDefinitions;

static LEDManagerAgent LEDManagerInstance;
RFAgent * const LEDManager = (RFAgent* const)&LEDManagerInstance.baseAgent;

static RFHandle initialState(LEDManagerAgent* const me, RFEvent *const evt);
static RFHandle LEDOnState(LEDManagerAgent* const me, RFEvent *const evt);

void LEDManagerConstructor(RFAgent * const self)
{
	assert(self == LEDManager);
	LEDManagerAgent *const me = (LEDManagerAgent* const)self;
	RFBaseAgentConstructor((RFAgent*)me, &initialState);
	RFTimerConstructor(self, &((LEDManagerAgent*)self)->flashingPeriodTimer, (uint32_t) LED_MANAGER_FLASHING_TIMEOUT_IN_MS);
}

RFHandle initialState(LEDManagerAgent* const me, RFEvent *const evt)
{
	(void)evt;
	(void)me;
	INITIAL_TRANSITION(me, &LEDOnState);
}

RFHandle LEDOnState(LEDManagerAgent* const me, RFEvent *const evt)
{
	switch (evt->signalValue)
	{
		case RF_INITIAL_SIGNAL:
		{
			CP_HD_LED_switchLEDOn();
			return RF_HANDLED;
		}
		case RF_ENTRY_SIGNAL:
		{
			CP_HD_LED_switchLEDOn();
			return RF_HANDLED;
		}
	}
	return RF_UNHANDLED;
}

