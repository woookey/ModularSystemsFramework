#include <CP_HA_LED.h>
#include <LEDType.h>

typedef GPIO_TypeDef* GPIO_TypeDefRef;

GPIO_TypeDefRef CPUActivityLEDInstance_GPIODef = GPIOD;
struct LEDType CPUActivityLEDInstance =
{
		.GPIOTypeDef_t = CPUActivityLEDInstance_GPIODef,
		.GPIOInitTypeDef_t =
		{
				.Pin = GPIO_PIN_12,
				.Mode = GPIO_MODE_OUTPUT_PP,
				.Pull = GPIO_PULLUP,
				.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
		},
};

GPIO_TypeDefRef powerOnIndicationLEDInstance_GPIODef = GPIOC;
struct LEDType powerOnIndicationLEDInstance =
{
		.GPIOTypeDef_t = powerOnIndicationLEDInstance_GPIODef,
		.GPIOInitTypeDef_t =
		{
				.Pin = GPIO_PIN_0,
				.Mode = GPIO_MODE_OUTPUT_PP,
				.Pull = GPIO_PULLUP,
				.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
		},
};

GPIO_TypeDefRef executingIndicationLEDInstance_GPIODef = GPIOC;
struct LEDType executingIndicationLEDInstance =
{
		.GPIOTypeDef_t = powerOnIndicationLEDInstance_GPIODef,
		.GPIOInitTypeDef_t =
		{
				.Pin = GPIO_PIN_1,
				.Mode = GPIO_MODE_OUTPUT_PP,
				.Pull = GPIO_PULLUP,
				.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
		},
};

GPIO_TypeDefRef safetyStopIndicationLEDInstance_GPIODef = GPIOC;
struct LEDType safetyStopIndicationLEDInstance =
{
		.GPIOTypeDef_t = safetyStopIndicationLEDInstance_GPIODef,
		.GPIOInitTypeDef_t =
		{
				.Pin = GPIO_PIN_2,
				.Mode = GPIO_MODE_OUTPUT_PP,
				.Pull = GPIO_PULLUP,
				.Speed = GPIO_SPEED_FREQ_VERY_HIGH,
		},
};

CPUActivityLED = &CPUActivityLEDInstance;
powerOnIndicationLED = &powerOnIndicationLEDInstance;
executingIndicationLED = &executingIndicationLEDInstance;
safetyStopIndicationLED = &safetyStopIndicationLEDInstance;

void CP_HA_LEDConstruct(CP_HA_LEDStruct LEDInstance)
{
	HAL_GPIO_Init(&LEDInstance->GPIOTypeDef_t, &LEDInstance->GPIOInitTypeDef_t);
}

void CP_HA_LEDSwitchOn(CP_HA_LEDStruct LEDInstance)
{
	HAL_GPIO_WritePin(&LEDInstance->GPIOTypeDef_t,
			LEDInstance->GPIOInitTypeDef_t.Pin, GPIO_PIN_SET);
}

void CP_HA_LEDSwitchOff(CP_HA_LEDStruct LEDInstance)
{
	HAL_GPIO_WritePin(&LEDInstance->GPIOTypeDef_t,
				LEDInstance->GPIOInitTypeDef_t.Pin, GPIO_PIN_RESET);
}

