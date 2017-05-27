CUR_DIR = $(shell pwd)
CC = arm-none-eabi-gcc
CC_CONFIG = --specs=nosys.specs -g -Wall
CPU_CONFIG = -mthumb -mcpu=cortex-m4
CMSIS_CORE_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Include/
CMSIS_STM32F4XX_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Include/
CMSIS_STARTUP_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc
CMSIS_SYSTEM_CONFIG_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Source/Templates
CFLAGS = -I ${CMSIS_CORE_INC_PATH} -I ${CMSIS_STM32F4XX_INC_PATH}
LINKER_SCRIPT = STM32F407VGTx_FLASH.ld
LINKER_PATH = /home/wookie/Development/ARMDev/src/lib/STM32F407_Linker/
LFLAGS = -T ${LINKER_SCRIPT} -L ${LINKER_PATH}

INCLUDE_DIRS = -I./
INCLUDE_DIRS +=  -I../../components/LEDManager/

DEPENDENCIES = ../../components/LEDManager/fakeLED.o


ARM_main: ${DEPENDENCIES}
	${CC} ${CC_CONFIG} ${CPU_CONFIG} -Os \
	${CFLAGS} ${INCLUDE_DIRS} ${LFLAGS} ${CMSIS_STARTUP_INC_PATH}/startup_stm32f407xx.s \
	${DEPENDENCIES} ARM_main.c ${CMSIS_SYSTEM_CONFIG_INC_PATH}/system_stm32f4xx.c -o ARM_main.axf;
	arm-none-eabi-objcopy -O binary ARM_main.axf ARM_main.bin
	
clean:
	rm -rf *~ *.axf *.bin