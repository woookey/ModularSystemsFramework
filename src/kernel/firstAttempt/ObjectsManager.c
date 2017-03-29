#include <ObjectsManager.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct
{
	AEvent eventNo;
	bool isActive;
} AEventBase;

typedef struct
{
	AEventBase event;
	/**
	 * TODO: This has to contain a 2D array with pointers to Agent
	 * instead of Agents as it is now
	 */
	baseAgentObject *subscribers;
	uint32_t subscribedAgentsNo;
} ASignal;

/**
 * -------------------------------
 * TODO Move this to Signal space.c (automated)
 *
 *
 */
static baseAgentObject agentsForSubscription[SYSTEM_SIG_END_OF_SPACE][MAX_NO_ACTIVE_AGENTS] =
{
	{0},
	{0},
	{0},
};

static ASignal ObjectManagerSignals [SYSTEM_SIG_END_OF_SPACE] =
{
	{{INITIAL_SYSTEM_SIGNAL, false}, agentsForSubscription[INITIAL_SYSTEM_SIGNAL], 0},
	{{NEW_SIG_FOR_AGENT_EXPERIMENT, false}, agentsForSubscription[NEW_SIG_FOR_AGENT_EXPERIMENT], 0},
	{{NEW_SIG_FOR_AGENT_LOGGER, false}, agentsForSubscription[NEW_SIG_FOR_AGENT_LOGGER], 0}
};
/*-------------------------------*/

bool ASubscribe(baseAgentObject me, AEvent event)
{
	assert(me != NULL);
	assert(event >= 0 && event < SYSTEM_SIG_END_OF_SPACE);
	/**
	 * TODO: Make a static assert from this somewhere else
	 */
	assert(event < MAX_NO_EVENTS_SUBSCRIBED);

	if (ObjectManagerSignals[event].subscribedAgentsNo == MAX_NO_ACTIVE_AGENTS)
	{
		return false;
	}
	else
	{
		ObjectManagerSignals[event].subscribers[ObjectManagerSignals[event].subscribedAgentsNo] = me;
		ObjectManagerSignals[event].subscribedAgentsNo++;
		return true;
	}
}

void APublish(AEvent event)
{
	assert(event >= 0 && event < SYSTEM_SIG_END_OF_SPACE);

	ObjectManagerSignals[event].event.isActive = true;
}

void ObjectManagerScheduler(void)
{
	uint32_t event_i;
	for (event_i = 0; event_i < SYSTEM_SIG_END_OF_SPACE; event_i++)
	{
		/**
		 * Run all the subscribers if the signal becomes active
		 */
		if (ObjectManagerSignals[event_i].event.isActive)
		{
			ObjectManagerSignals[event_i].event.isActive = false;
			uint32_t agent_i;
			/**
			 * TODO: This should only insert an event to the memory pool of each agent
			 */
			for (agent_i = 0; agent_i < ObjectManagerSignals[event_i].subscribedAgentsNo; agent_i++)
			{
				assert(ObjectManagerSignals[event_i].subscribers[agent_i] != NULL);
				assert(ObjectManagerSignals[event_i].subscribers[agent_i]->currentHandler != NULL);
				ObjectManagerSignals[event_i].subscribers[agent_i]
					->currentHandler(ObjectManagerSignals[event_i].subscribers[agent_i], event_i);
			}
		}
	}
}

void baseAgentConstructor(baseAgentObject agent)
{
	assert(agent != NULL);

	agent->currentHandler = NULL;
	agent->eventPoolHEAD = NULL;
	printf("Created base Agent.\n");
}
