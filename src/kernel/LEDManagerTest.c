#include <assert.h>
#include <stdio.h>
#include <RF_dispatcher.h>
#include "LEDManagerTest.h"

typedef struct
{
	RFAgent RFbase;
	uint32_t LEDParameterForTesting;
}LEDManagerTest;

LEDManagerTest LEDManagerTestInstance;
RFAgent *const HW_RF_LEDManagerTest = (RFAgent*)&LEDManagerTestInstance;

static RFHandle InitialState(LEDManagerTest* const self, RFEvent *const evt);
static RFHandle LEDOnState(LEDManagerTest* const self, RFEvent *const evt);
//static void LEDOffState(LEDManager* const self, RFEvent *const evt);

static void generateSignalFourAndPostToItself(LEDManagerTest* const self);

void HW_RF_LEDManagerTestConstructor(RFAgent *const self)
{
	assert(self == HW_RF_LEDManagerTest);
	LEDManagerTest *const me = (LEDManagerTest*)self;

	RFBaseAgentConstructor((RFAgent*)me, &InitialState);
	me->LEDParameterForTesting = 5;
}

RFHandle InitialState(LEDManagerTest* const self, RFEvent *const evt)
{
	(void)evt;
	INITIAL_TRANSITION((RFAgent*)&self->RFbase, LEDOnState);
}


RFHandle LEDOnState(LEDManagerTest* const self, RFEvent *const evt)
{

	switch(evt->signalValue)
	{
		case RF_INITIAL_SIGNAL:
		{
			printf("LED switched on\n");
			generateSignalFourAndPostToItself(self);
			return RF_HANDLED;
		}
		case 4:
		{
			printf("Received event: %d\n", evt->signalValue);
			return RF_HANDLED;
		}
		default:
		{
			printf("Received default event: %d\n", evt->signalValue);
			return RF_HANDLED;
		}
	}
}

void generateSignalFourAndPostToItself(LEDManagerTest* const self)
{
	static RFEvent LEDEvent =
	{
		.signalValue = 4,
		.pendingConsumers = 0,
		.eventSize = sizeof(RFEvent),
	};
	postEventToAgent(&self->RFbase, (RFEvent const* const)&LEDEvent);
}
