#ifndef SYSTEM_SIGNALS
#define SYSTEM_SIGNALS

typedef enum
{
	INITIAL_SYSTEM_SIGNAL = 0,
	NEW_SIG_FOR_AGENT_EXPERIMENT = 1,
	NEW_SIG_FOR_AGENT_LOGGER,
	SYSTEM_SIG_END_OF_SPACE
} SysSignal;

#endif
