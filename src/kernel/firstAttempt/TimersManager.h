#ifndef TIMERS_MANAGER_H
#define TIMERS_MANAGER_H

#include <stdint.h>
#include <stdbool.h>

/**
 * Each BaseTimer is based on the sysTick
 * being handled by the ObjectsManager and is
 * a multiple of a sysTick basic counter
 *
 * For example, when sysTick is configured as 1ms
 * timer cannot be configured as 2.5ms (only if sysTick
 * was 0.5ms)
 */
struct BaseTimer
{
	uint32_t timerCountdown;
	bool pendingHandlng;
	bool isEnabled;
	uint32_t signal;
};

typedef struct BaseTimer BaseTimer_t;
typedef BaseTimer_t* const TimerEvent;


/**
 * Decreases the TimerEvent by one sysTick
 */
void decreaseCounter(TimerEvent TEvt);
TimerEvent constructTimerEvent(TimerEvent self, uint32_t requiredTime);
void disableTimerEvent(TimerEvent TEvt);
void enableTimerEvent(TimerEvent TEvt);
void reenableTimerEvent(TimerEvent TEvt);
#endif
