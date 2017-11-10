#include <LEDManager.h>
#include <CP_HD_LEDDriver.h>
//#include <RF_timers.h>
#include <assert.h>

typedef struct
{
	RFAgent baseAgent;
	//RF_Timer flashingPeriodTimer;
} LEDManagerAgent;

static LEDManagerAgent LEDManagerInstance;
RFAgent * const LEDManager = (RFAgent* const)&LEDManagerInstance.baseAgent;

static RFHandle initialState(LEDManagerAgent* const me, RFEvent *const evt);
static RFHandle LEDOffState(LEDManagerAgent* const me, RFEvent *const evt);

void LEDManagerConstructor(RFAgent * const self)
{
	assert(self == LEDManager);
	LEDManagerAgent *const me = (LEDManagerAgent* const)self;
	RFBaseAgentConstructor((RFAgent*)me, &initialState);
}

RFHandle initialState(LEDManagerAgent* const me, RFEvent *const evt)
{
	(void)evt;
	(void)me;
	INITIAL_TRANSITION(me, &LEDOffState);
}

RFHandle LEDOffState(LEDManagerAgent* const me, RFEvent *const evt)
{
	switch (evt->signalValue)
	{
		case RF_INITIAL_SIGNAL:
		{
			CP_HD_LED_switchLEDOff();
			return RF_HANDLED;
		}
		case RF_ENTRY_SIGNAL:
		{
			CP_HD_LED_switchLEDOff();
			return RF_HANDLED;
		}
	}
	return RF_UNHANDLED;
}

