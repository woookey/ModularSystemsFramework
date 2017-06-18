#include <stm32f4xx.h>
#include <stdint.h>

#define ORANGE_LED_SET 13
#define ORANGE_LED_RESET 29
#define LED_ON() GPIOD->BSRR |= (1 << ORANGE_LED_SET)
#define LED_OFF() GPIOD->BSRR |= (1 << ORANGE_LED_RESET)

static void delay(int n);
static void initHardware(void);
static void initClocks(void);

int main()
{
	initClocks();
	initHardware();
	SystemCoreClockUpdate();

	while(1)
	{
		LED_ON();
		delay(8000000);
		LED_OFF();
		delay(8000000);
	}
	return 0;
}

void delay(int n)
{
	volatile int i = 0;
	while (i < n) {i++;}
}

void initHardware(void)
{
	/* Enable GPIOA clock */
		RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
		/* Configure GPIOA pin 5 as output */
		GPIOD->MODER |= (1 << (ORANGE_LED_SET << 1));
		/* Configure GPIOA pin 5 in max speed */
		GPIOD->OSPEEDR |= (3 << (ORANGE_LED_SET << 1));
}

void initClocks(void) {}
