#include <unity.h>
#include <RF_events.h>

static RFEvent sampleEvt =
{
	.eventSize = sizeof(RFEvent),
	.pendingConsumers = 0,
	.signalValue = 150,
};

static void run_nothing(void);

int main() {
	UNITY_BEGIN();
	RUN_TEST(run_nothing);
	return UNITY_END();
}

void run_nothing(void)
{
	(void)sampleEvt;
}
