#include <unity.h>
#include <stdbool.h>

static void run_CheckingCreatingDispatcher(void);

int main() {
	UNITY_BEGIN();
	RUN_TEST(run_CheckingCreatingDispatcher);
	return UNITY_END();
}

void run_CheckingCreatingDispatcher(void)
{
	TEST_ASSERT(true);
}
