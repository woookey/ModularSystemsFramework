#ifndef OBJECTS_MANAGER_H
#define OBJECTS_MANAGER_H

#include <stdint.h>
#include <stdbool.h>
#include <SignalSpace.h>

#define MAX_NO_EVENTS_SUBSCRIBED UINT_MAX
#define LAST_SIGNAL_SPACE_SIG_NO (SYSTEM_SIG_END_OF_SPACE-1)
#define MAX_NO_ACTIVE_AGENTS 10

typedef uint32_t AEvent;
typedef AEvent* RF_EventObject;

struct baseAgent
{
	void (*currentHandler)(struct baseAgent* self, AEvent event);
	RF_EventObject* eventPoolHEAD;
};

/**
 * Transitions the agent to the initial function
 * and generated INITIAL_SYSTEM_SIGNAL on transition
 */
#define INIT_TRANS(_func) \
	me->currentHandler = _func; \
	me->currentHandler(me, INITIAL_FRAMEWORK_SIGNAL)

/**
 * Transitions the agent from one state to another
 * and generates INITIAL_SYSTEM_SIGNAL on transition
 */
#define STATE_TRANS(_func) \
	me->currentHandler = _func; \
	me->currentHandler(me, ENTRY_FRAMEWORK_SIGNAL)

typedef struct baseAgent baseAgent_t;
typedef baseAgent_t * baseAgentObject;

void baseAgentConstructor(baseAgentObject agent);
void ObjectManagerScheduler(void);
bool ASubscribe(baseAgentObject me, AEvent event);
void APublish(AEvent event);

#endif
