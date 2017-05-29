#include <LEDManager.h>
//#include <RF_timers.h>
#include <assert.h>
#include <stdio.h>

typedef struct
{
	RFAgent baseAgent;
	//RF_Timer flashingPeriodTimer;
} LEDManagerAgent;

static LEDManagerAgent LEDManagerInstance;
RFAgent * const LEDManager = (RFAgent* const)&LEDManagerInstance.baseAgent;

static RFHandle initialState(LEDManagerAgent* const me, RFEvent *const evt);
static RFHandle LEDOffState(LEDManagerAgent* const me, RFEvent *const evt);

/**
 * Functions calling hardware - to be removed
 */
static void switchLEDOff(void);
//static void switchLEDOn(void);

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
			switchLEDOff();
			return RF_HANDLED;
		}
		case RF_ENTRY_SIGNAL:
		{
			switchLEDOff();
			return RF_HANDLED;
		}
		default:
		{
			printf("LEDManager received default sig\n");
			return RF_HANDLED;
		}
	}
}

void switchLEDOff(void)
{
	printf("LED switched off...\n");
}

/*void switchLEDOn(void)
{
	printf("LED switched on...\n");
}*/
