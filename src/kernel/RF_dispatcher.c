#include <RF_dispatcher.h>
#include <RF_definitions.h>
#include <RF_queue.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

#define NUMBER_OF_SIGNALS_REQUIRED_BY_FRAMEWORK RF_LAST_SIGNAL

typedef struct
{
	uint16_t noOfRegisteredAgents;
	uint16_t noOfRegisteredSignals;
	//RFAgent** subscribers;
} RF_Dispatcher;

static RFAgent* subscribersInstance[RF_MAX_NUMBER_OF_SIGNALS][RF_MAX_NUMBER_OF_AGENTS] = {NULL};
static RF_Dispatcher dispatcherInstance;
/*{
		.subscribers = subscribersInstance,
};*/

void RF_DispatcherCtor(void)
{
	memset(subscribersInstance, NULL,
			sizeof(RFAgent*)*RF_MAX_NUMBER_OF_SIGNALS*RF_MAX_NUMBER_OF_AGENTS);
	memset(&dispatcherInstance, 0, sizeof(RF_Dispatcher));
	dispatcherInstance.noOfRegisteredAgents = 0;
	dispatcherInstance.noOfRegisteredSignals = NUMBER_OF_SIGNALS_REQUIRED_BY_FRAMEWORK;
}

void RF_Dispatcher_RegisterNumberOfEvents(uint16_t noOfExpectedEvents)
{
	assert(noOfExpectedEvents > 0 && noOfExpectedEvents <= RF_MAX_NUMBER_OF_SIGNALS);
	dispatcherInstance.noOfRegisteredSignals = noOfExpectedEvents;
}

void RF_Dispatcher_RegisterNumberOfAgents(uint16_t noOfExpectedAgents)
{
	assert(noOfExpectedAgents > 0 && noOfExpectedAgents <= RF_MAX_NUMBER_OF_AGENTS);
	dispatcherInstance.noOfRegisteredAgents = noOfExpectedAgents;
}

void postEventToAgent(RFAgent* self, RFEvent const * const evt)
{
	assert(self != NULL);
	assert(evt != NULL);
	self->FIFOQueue.push(&self->FIFOQueue, (RFEvent*)evt, evt->eventSize);
}

/**
 * Subscribes an agent to the signal
 */
void subscribeAgentToSignal(RFAgent* agent, uint32_t signalValue)
{
	assert(agent != NULL);
	assert(signalValue >= 0 && signalValue <= dispatcherInstance.noOfRegisteredSignals);
	uint16_t agentSlot;
	/**
	 * Do not add the agent if it is already subscribed
	 */
	for (agentSlot = 0; agentSlot < dispatcherInstance.noOfRegisteredAgents; agentSlot++)
	{
		if (subscribersInstance[signalValue][agentSlot] == agent)
		{
			printf("Agent already allocated at (%d, %d)\n", signalValue, agentSlot);
			return;
		}
	}
	for (agentSlot = 0; agentSlot < dispatcherInstance.noOfRegisteredAgents; agentSlot++)
	{
		if (subscribersInstance[signalValue][agentSlot] == NULL)
		{
			printf("Agent will be allocated at (%d, %d)\n", signalValue, agentSlot);
			subscribersInstance[signalValue][agentSlot] = agent;
			return;
		}
	}
	assert(false);
}

void unsubscribeAgentToSignal(RFAgent* self, uint32_t signalValue)
{
	assert(self != NULL);
	assert(signalValue >= 0 && signalValue <= dispatcherInstance.noOfRegisteredSignals);
	uint16_t agentSlot;
	for (agentSlot = 0; agentSlot < dispatcherInstance.noOfRegisteredAgents; agentSlot++)
	{
		if (subscribersInstance[signalValue][agentSlot] == self)
		{
			subscribersInstance[signalValue][agentSlot] = NULL;
			/**
			 * TODO:
			 * Shift the memory to the left by one agent to align with subscribed agents
			 */
		}
	}
}

void publishEvent(RFEvent const* const evt)
{
	assert(evt != NULL);
	uint16_t agentSlot;
	for (agentSlot = 0; agentSlot < dispatcherInstance.noOfRegisteredAgents; agentSlot++)
	{
		if (subscribersInstance[evt->signalValue][agentSlot] != NULL)
		{
			RFAgent* subscribedAgent = subscribersInstance[evt->signalValue][agentSlot];
			subscribedAgent->FIFOQueue.push(&subscribedAgent->FIFOQueue, (RFEvent*)evt, evt->eventSize);
		}
	}
}
