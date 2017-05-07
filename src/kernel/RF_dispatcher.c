#include <RF_dispatcher.h>
#include <RF_definitions.h>
#include <RF_queue.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

typedef struct
{
	RF_Queue eventsQueue;
	uint16_t noOfAgents;
	uint16_t noOfEvents;
	RFAgent** subscribers;
} RF_Dispatcher;

static struct RF_BaseQueue dispatcherQueue;
static RFAgent memoryPoolForDispatcherEvents[RF_DISPATCHER_MEMORY_POOL_SIZE];
static RFAgent* subscribersInstance[RF_MAX_NUMBER_OF_SIGNALS][RF_MAX_NUMBER_OF_AGENTS] = {NULL};
static RF_Dispatcher dispatcherInstance =
{
		.eventsQueue = &dispatcherQueue,
		.noOfAgents = 0,
		.noOfEvents = 0,
		.subscribers = subscribersInstance,
};

void RF_DispatcherCtor(void)
{
	memset(dispatcherInstance.subscribers, NULL, sizeof(subscribersInstance));
	createEmptyQueue(dispatcherInstance.eventsQueue, memoryPoolForDispatcherEvents,
			sizeof(RFAgent)*RF_DISPATCHER_MEMORY_POOL_SIZE);
}

void postEventToAgent(RFAgent* self, RFEvent const * const evt)
{
	assert(self != NULL);
	assert(evt != NULL);
	self->FIFOQueue.push(&self->FIFOQueue, evt, evt->eventSize);
}

/**
 * Subscribes an agent to the signal
 */
void subscribeAgentToSignal(RFAgent* agent, uint32_t signalValue)
{
	assert(agent != NULL);
	assert(signalValue >= 0 && signalValue < RF_MAX_NUMBER_OF_SIGNALS);
	uint16_t agentSlot;
	/**
	 * Do not add the agent if it is already subscribed
	 */
	for (agentSlot = 0; agentSlot < RF_MAX_NUMBER_OF_AGENTS; agentSlot++)
	{
		if (&dispatcherInstance.subscribers[signalValue][agentSlot] == agent)
		{
			return;
		}
	}
	for (agentSlot = 0; agentSlot < RF_MAX_NUMBER_OF_AGENTS; agentSlot++)
	{
		if (&dispatcherInstance.subscribers[signalValue][agentSlot] == NULL)
		{
			//&dispatcherInstance.subscribers[signalValue][agentSlot] = (RFAgent*)agent;
			memcpy(&dispatcherInstance.subscribers[signalValue][agentSlot], &agent, sizeof(RFAgent*));
			return;
		}
	}
	assert(false);
}

/**
 * Publishes an event
 */
void publishEvent(RFEvent const* const evt)
{
	assert(evt != NULL);
	dispatcherInstance.eventsQueue->push(&dispatcherInstance.eventsQueue, evt, evt->eventSize);
}
