#include <stdio.h>
#include <RF_queue.h>
#include <RF_events.h>
#include <unity.h>

static void run_CheckingJustCreatedQueue(void);
static void compareSizeOfInitialisedQueueWithNumber(uint8_t expectedSizeInEvents);

#define POOL_SIZE_IN_EVENTS (uint8_t)10
static struct RF_BaseQueue testedQueue;
static RFEvent eventsPool[POOL_SIZE_IN_EVENTS];


int main()
{
	UNITY_BEGIN();
	createEmptyQueue(&testedQueue, eventsPool, sizeof(eventsPool));
	RUN_TEST(run_CheckingJustCreatedQueue);
	return UNITY_END();
}

void run_CheckingJustCreatedQueue(void)
{
	compareSizeOfInitialisedQueueWithNumber(POOL_SIZE_IN_EVENTS);
	TEST_ASSERT(testedQueue.isEmpty);
	TEST_ASSERT(!testedQueue.isFull);
	TEST_ASSERT(testedQueue.pop != NULL);
	TEST_ASSERT(testedQueue.push != NULL);
	TEST_ASSERT(testedQueue.HEAD == &eventsPool[0])
	TEST_ASSERT(testedQueue.HEAD == testedQueue.TAIL);
}

void compareSizeOfInitialisedQueueWithNumber(uint8_t expectedSizeInEvents)
{
	TEST_ASSERT_EQUAL_UINT8(expectedSizeInEvents*sizeof(RFEvent), (uint8_t)testedQueue.totalSize);
	TEST_ASSERT_EQUAL_UINT8(expectedSizeInEvents*sizeof(RFEvent), (uint8_t)testedQueue.spaceLeft);
}
