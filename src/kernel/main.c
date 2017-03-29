#include <stdio.h>
#include <RF_agents.h>
#include <RF_scheduler.h>
#include <LEDManager.h>

static void runRFKernel(void);

int main()
{
	printf("Starting ARM program...\n");
	/**
	 * Creating Agents
	 */
	startAgent(HW_RF_LEDManager, HW_RF_LEDManagerConstructor, AGENT_PRIORITY_0);

	runRFKernel();
	return 0;
}

void runRFKernel(void)
{
	printf("Starting Robot Framework kernel...\n");
	runScheduler();
}
