#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <RF_timers.h>
#include <systemSignals.h>

#include <stdint.h>
#include <stm32f4xx_hal_conf.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_rcc_ex.h>
#include <stm32f4xx_hal.h>
#include <assert.h>

static void setupHardware(void);
static void initClocks(void);

int main()
{
	SystemInit();
	SystemCoreClockUpdate();
	setupHardware();
	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();


	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
						&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);
	while(1)
	{
		runScheduler();
	}
	return 0;
}

void setupHardware(void)
{
	initClocks();
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
}

static void initClocks()
{
	// TODO: Verify the speed of clock
    HAL_RCC_DeInit();
    RCC_OscInitTypeDef rccOscInstance =
    {
    		.OscillatorType = RCC_OSCILLATORTYPE_HSE,
			.HSEState = RCC_HSE_ON,
			.LSEState = RCC_LSE_OFF,
			.HSIState = RCC_HSI_OFF,
			.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT,
			.LSIState = RCC_LSI_OFF,
			.PLL =
			{
					.PLLState = RCC_PLL_ON,
					.PLLSource = RCC_PLLSOURCE_HSE,
					.PLLM = 8,
					.PLLN = 336,
					.PLLP = RCC_PLLP_DIV2,
					.PLLQ = 7,
			},
    };
    assert(HAL_RCC_OscConfig(&rccOscInstance) == HAL_OK);

    RCC_ClkInitTypeDef rccClkInstance =
    {
    		  .ClockType = RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_HCLK,
    		  .SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK,
    		  .AHBCLKDivider = RCC_SYSCLK_DIV1,
    		  .APB1CLKDivider = RCC_HCLK_DIV4,
    		  .APB2CLKDivider = RCC_HCLK_DIV2,
    };

    assert(HAL_RCC_ClockConfig(&rccClkInstance, FLASH_ACR_LATENCY_5WS) == HAL_OK);
}

void SysTick_Handler(void)
{
	HAL_IncTick();
	RFTimer_decreaseTimersByOneTick();
}
