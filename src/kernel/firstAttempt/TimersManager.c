#include <TimersManager.h>

void decreaseCounter(TimerEvent TEvt);
TimerEvent constructTimerEvent(uint32_t requiredTime);
void disableTimerEvent(TimerEvent TEvt);
void enableTimerEvent(TimerEvent TEvt);
void reenableTimerEvent(TimerEvent TEvt);
#endif
