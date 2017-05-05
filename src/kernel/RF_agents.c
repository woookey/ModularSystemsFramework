#include <RF_agents.h>
#include <stdlib.h>
#include <assert.h>

void RFBaseAgentConstructor(RFAgent* const self, void (*initialTransition)(RFAgent* const self, RFEvent *const evt))
{
	assert(self != NULL);
	INITIAL_TRANSITION(self, initialTransition);
}
