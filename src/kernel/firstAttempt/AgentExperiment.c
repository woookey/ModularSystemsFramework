#include <AgentExperiment.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

struct baseAgent ExperimentAgentInstance;
baseAgentObject ExperimentAgent = &ExperimentAgentInstance;

static void RunExperimentAgent(baseAgentObject me, AEvent event);

void ConstructExperimentAgent(baseAgentObject me)
{
	assert(me != NULL);
	assert(me == ExperimentAgent);
	baseAgentConstructor(me);
	assert(ASubscribe(me, NEW_SIG_FOR_AGENT_EXPERIMENT));
	printf("Created Experiment Agent.\n");
	INIT_TRANS(&RunExperimentAgent);
}

/**
 * TODO: Finish experimentAgent and LoggerAgent with first function
 * TODO2: * void RunExperimentAgent(baseAgentObject me, AEvent event)
 */
void RunExperimentAgent(baseAgentObject me, AEvent event)
{
	assert(me == ExperimentAgent);
	static uint32_t run = 0;
	printf("Experimental Agent(%d), Event value = %d\n", run++, event);
}
