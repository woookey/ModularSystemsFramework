/**
 * Agents are the core elements of the Robotic Framework
 * which correspond to state machines executing the program
 * and transmitting information between each other
 */
#ifndef ROBOTIC_FRAMEWORK_AGENTS_H
#define ROBOTIC_FRAMEWORK_AGENTS_H

#include <RF_events.h>

struct RFBaseAgent
{
	RFEvent ** eventsPtr;
	uint32_t totalStackSize;

	void (*currentHandler)(struct RFBaseAgent* const self, RFEvent *const evt);
};

/**
 * TODO: Change in other files using struct RFBaseAgent to RFAgent
 */
typedef struct RFBaseAgent RFAgent;

void RFBaseAgentConstructor(struct RFBaseAgent* const self);

#endif
