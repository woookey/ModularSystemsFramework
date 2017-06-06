#include <stm32f4xx.h>
#include <LEDManager.h>
#include <RF_events.h>
#include <RF_scheduler.h>
#include <RF_dispatcher.h>
#include <systemSignals.h>
#include <stdint.h>
#include <stm32f4xx_hal_conf.h>
#include <stm32f4xx_hal_rcc.h>
#include <stm32f4xx_hal_rcc_ex.h>
#include <assert.h>

#define PIN7 7
#define LED_ORANGE 13

static void dumbDelay(uint32_t tickCounts);
static void setupHardware(void);
static void switchOrangeOn(void);
static void switchOrangeOff(void);
static void initClocks(void);

int main()
{
	setupHardware();
	while (1)
	{
		switchOrangeOn();
		dumbDelay(16800000);
		switchOrangeOff();
		dumbDelay(16800000);
	}


	RFEvent LEDManagerPool[10];
	RF_DispatcherCtor();
	startAgent(LEDManager, &LEDManagerConstructor, AGENT_PRIORITY_0,
			&LEDManagerPool[0], sizeof(RFEvent)*10);

	RF_Dispatcher_RegisterNumberOfAgents(1);
	RF_Dispatcher_RegisterNumberOfEvents(SYSTEM_SIGNAL_NUMBER_OF_SIGNALS);

	runScheduler();
	return 0;
}

void setupHardware(void)
{
	initClocks();

	SystemCoreClockUpdate();

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;

	GPIOC->MODER |= (1 << (PIN7 << 1));
	GPIOC->OSPEEDR |= (3 << (PIN7 << 1));
	GPIOC->BSRR |= (1 << PIN7);

	GPIOD->MODER |= (1 << (LED_ORANGE << 1));
	GPIOD->OSPEEDR |= (3 << (LED_ORANGE << 1));
}

static void dumbDelay(uint32_t tickCounts)
{
	while(tickCounts--) {}
}

static void switchOrangeOn(void) {GPIOD->BSRR |= (1 << LED_ORANGE);}
static void switchOrangeOff(void) {GPIOD->BSRR &= (0 << LED_ORANGE);}


static void initClocks()
{
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

/*static void HA_Clocks_InitSYSCLK()
{
    RCC_SYSCLKConfig(RCC_SYSCLKSource_PLLCLK);
    Q_REQUIRE(SUCCESS == RCC_WaitForClockSourceSwitch(RCC_CFGR_SWS_PLL));
    SysTick_CLKSourceConfig(SysTick_CLKSource_HCLK);
}*/
