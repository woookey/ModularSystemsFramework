#include <RF_scheduler.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_NUMBER_OF_AGENTS 50

typedef struct
{
	RFAgent** agentsList;
	uint32_t numberOfAgents;
}RFScheduler;

RFAgent* listOfAgentsForSchedulingInstance [MAX_NUMBER_OF_AGENTS] = {NULL};

static RFScheduler RFSchedulerObject =
{
		.agentsList = listOfAgentsForSchedulingInstance,
		.numberOfAgents = 0,
};

void startAgent(RFAgent* newAgent, void (*agentCtor)(RFAgent* const self),
		RF_SchedulerPriority agentPrio)
{
	assert(newAgent != NULL);
	assert(agentCtor != NULL);
	assert(agentPrio >= 0 && agentPrio < AGENT_PRIORITY_END_OF_PRIORITY_SPACE);

	RFSchedulerObject.agentsList[RFSchedulerObject.numberOfAgents] = newAgent;
	RFSchedulerObject.numberOfAgents++;

	/**
	 * Constructing the agent
	 */
	agentCtor(newAgent);
}

void runScheduler(void)
{
	/**
	 * Superloop(to be added) based on scheduling policy
	 * At the moment each agent is equally important and
	 * they are executed in the same order they were started
	 */
	assert(RFSchedulerObject.numberOfAgents > 0 && RFSchedulerObject.numberOfAgents <= MAX_NUMBER_OF_AGENTS);
	uint32_t agentNumber;
	for(agentNumber = 0; agentNumber < RFSchedulerObject.numberOfAgents; agentNumber++)
	{
		RFSchedulerObject.agentsList[agentNumber]->currentHandler
		(RFSchedulerObject.agentsList[agentNumber],(RFEvent *const)&RFEvent_InitialSignal);
	}
}
