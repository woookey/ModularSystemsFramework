#include <LEDManager.h>
#include <assert.h>
#include <stdio.h>
#include <RF_dispatcher.h>

typedef struct
{
	RFAgent RFbase;
	uint32_t LEDParameterForTesting;
}LEDManager;

LEDManager LEDManagerInstance;
RFAgent *const HW_RF_LEDManager = (RFAgent*)&LEDManagerInstance;

/**
 * TODO: InitialState should be returning something so that
 * the scheduler knows that this agent finished its state machine execution(Run to completion)
 */
static RFHandle InitialState(LEDManager* const self, RFEvent *const evt);
static RFHandle LEDOnState(LEDManager* const self, RFEvent *const evt);
//static void LEDOffState(LEDManager* const self, RFEvent *const evt);

static void generateSignalFourAndPostToItself(LEDManager* const self);

void HW_RF_LEDManagerConstructor(RFAgent *const self)
{
	assert(self == HW_RF_LEDManager);
	LEDManager *const me = (LEDManager*)self;

	RFBaseAgentConstructor((RFAgent*)me, InitialState);
	me->LEDParameterForTesting = 5;
}

RFHandle InitialState(LEDManager* const self, RFEvent *const evt)
{
	(void)evt;
	INITIAL_TRANSITION((RFAgent*)&self->RFbase, LEDOnState);
}


RFHandle LEDOnState(LEDManager* const self, RFEvent *const evt)
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

void generateSignalFourAndPostToItself(LEDManager* const self)
{
	static RFEvent LEDEvent =
	{
		.signalValue = 4,
		.pendingConsumers = 0,
		.eventSize = sizeof(RFEvent),
	};
	postEventToAgent(&self->RFbase, (RFEvent const* const)&LEDEvent);
}
