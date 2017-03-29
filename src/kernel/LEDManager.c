#include <LEDManager.h>
#include <assert.h>
#include <stdio.h>

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
static void InitialState(LEDManager* const self, RFEvent *const evt);

void HW_RF_LEDManagerConstructor(RFAgent *const self)
{
	assert(self == HW_RF_LEDManager);
	LEDManager *const me = (LEDManager*)self;

	RFBaseAgentConstructor((RFAgent*)me);
	me->LEDParameterForTesting = 5;
	me->RFbase.currentHandler = InitialState;
}

void InitialState(LEDManager* const self, RFEvent *const evt)
{
	switch(evt->signalValue)
	{
		case RF_INITIAL_SIGNAL:
		{
			printf("LEDManager initial state, parameter = %d\n", self->LEDParameterForTesting);
		}
	}
}
