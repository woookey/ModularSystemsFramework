#include <RF_agents.h>
#include <stdlib.h>
#include <assert.h>

void RFBaseAgentConstructor(struct RFBaseAgent* const self)
{
	assert(self != NULL);
	self->eventsPtr = NULL;
	self->totalStackSize = 0;
	self->currentHandler = NULL;
}
