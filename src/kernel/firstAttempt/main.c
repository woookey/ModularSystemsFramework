#include <stdio.h>
#include <AgentExperiment.h>
#include <AgentLogger.h>
#include <SignalSpace.h>
#include <stdint.h>

static void runARM(void);

int main()
{
	printf("Start creating objects\n");
	ConstructExperimentAgent(ExperimentAgent);
	ConstructLoggerAgent(LoggerAgent);	
	printf("Hello ARM!\nStarting main...\n");
	runARM();
	/*uint32_t a = 0;
	while( a<=32 )
	{
		//printf("a = %d\n", a);
		ObjectManagerScheduler();
		if (a%5 == 0)
		{
			APublish(NEW_SIG_FOR_AGENT_EXPERIMENT);
		}
		if (a%10 == 0)
		{
			APublish(NEW_SIG_FOR_AGENT_LOGGER);
		}
		a++;
	}*/
	return 0;
}

void runARM(void)
{
	while(1)
	{
		ObjectManagerScheduler();
	}
}
