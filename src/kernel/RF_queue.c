#include <RF_queue.h>
#include <assert.h>
#include <stdlib.h>

static RFEvent* popFromQueue(struct RF_BaseQueue* self);
static void pushToQueue(struct RF_BaseQueue* self, RFEvent* evt, size_t sizeOfEvent);
static void removeGarbageFromQueue(struct RF_BaseQueue* self);


void createEmptyQueue(RF_Queue queue, RFEvent *memoryPoolAddress, size_t memoryPoolSize)
{
	assert(queue != NULL);
	assert(memoryPoolAddress != NULL);
	assert(memoryPoolSize > 0);
	queue->HEAD = &memoryPoolAddress[0];
	queue->TAIL = queue->HEAD;
	queue->isEmpty = true;
	queue->isFull = false;
	queue->pop = popFromQueue;
	queue->push = pushToQueue;
	queue->spaceLeft = memoryPoolSize;
	queue->totalSize = memoryPoolSize;
	queue->removeGarbage = removeGarbageFromQueue;
}

/**
 * Returns the pointer to the next event to be dispatched (FIFO basis)
 * Event is removed from the queue by queue cleaner after it has been
 * successfully processed
 */
RFEvent* popFromQueue(struct RF_BaseQueue* self)
{
	assert(self != NULL);
	assert(self->isEmpty);

	return self->HEAD;
}

void pushToQueue(struct RF_BaseQueue* self, RFEvent* evt, size_t sizeOfEvent)
{
	assert(sizeOfEvent <= self->spaceLeft);
	memcpy((self->TAIL+self->TAIL->eventSize), evt, sizeOfEvent);

	self->TAIL = self->TAIL + sizeOfEvent;
	self->isEmpty = false;
	self->spaceLeft = self->spaceLeft - sizeOfEvent;
	self->isFull = self->spaceLeft < sizeof(RFEvent) ? true : false;;
}

void removeGarbageFromQueue(struct RF_BaseQueue* self)
{
	assert(self != NULL);
	if (self->HEAD->pendingConsumers == 0)
	{
		memmove(self->HEAD, self->HEAD+self->HEAD->eventSize, self->totalSize - self->HEAD->eventSize);
	}
}

