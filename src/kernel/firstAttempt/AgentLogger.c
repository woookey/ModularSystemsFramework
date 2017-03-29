#include <AgentLogger.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct baseAgent LoggerAgentInstance;
baseAgentObject LoggerAgent = &LoggerAgentInstance;

static void RunLoggerAgent(baseAgentObject me, AEvent event);

static void PhaseOneFunc(baseAgentObject me, AEvent event);
static void PhaseTwoFunc(baseAgentObject me, AEvent event);
static void PhaseFinalFunc(baseAgentObject me, AEvent event);

void ConstructLoggerAgent(baseAgentObject me)
{
	assert(me != NULL);
	assert(me == LoggerAgent);
	baseAgentConstructor(me);
	assert(ASubscribe(me, NEW_SIG_FOR_AGENT_LOGGER));
	printf("Created Logger Agent.\n");
	INIT_TRANS(&RunLoggerAgent);
}

void RunLoggerAgent(baseAgentObject me, AEvent event)
{
	static uint32_t run = 0;
	printf("Logger Agent(%d), Event value = %d\n", run++, event);
	STATE_TRANS(&PhaseOneFunc);
}

void PhaseOneFunc(baseAgentObject me, AEvent event)
{
	switch(event)
	{
		case INITIAL_SYSTEM_SIGNAL:
		{
			printf("Entered PhaseOneFunc\n");
			break;
		}
		case NEW_SIG_FOR_AGENT_LOGGER:
		{
			STATE_TRANS(&PhaseTwoFunc);
			break;
		}
	}
}

void PhaseTwoFunc(baseAgentObject me, AEvent event)
{
	switch(event)
	{
		case INITIAL_SYSTEM_SIGNAL:
		{
			printf("Entered PhaseTwoFunc\n");
			break;
		}
		case NEW_SIG_FOR_AGENT_LOGGER:
		{
			STATE_TRANS(&PhaseFinalFunc);
			break;
		}
	}
}

void PhaseFinalFunc(baseAgentObject me, AEvent event)
{
	switch(event)
	{
		case INITIAL_SYSTEM_SIGNAL:
		{
			printf("Entered PhaseFinalFunc\n");
			break;
		}
	}
}

