/**
 * Main file of ARM project
 */

#include <stm32f4xx.h>
#include <fakeLED.h>

int main()
{
	createFakeLED();
	while(1);
	return 0;
}
