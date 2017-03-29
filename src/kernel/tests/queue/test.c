#include <stdio.h>
#include <RF_queue.h>
#include <RF_events.h>

int main()
{
	static struct RF_BaseQueue uninitialisedQueue;
	static RFEvent eventsPool[10];
	printf("Size of events = %ld\n", sizeof(RFEvent));
	printf("Size of eventsPool = %ld\n", sizeof(eventsPool));
	createEmptyQueue(&uninitialisedQueue, eventsPool, sizeof(eventsPool));
	return 0;
}
