CUR_DIR = $(shell pwd)
CC_TARGET = arm-none-eabi-gcc
CC_SYNTHETIC = gcc
CC_CONFIG = --specs=nosys.specs -g -Wall
CPU_CONFIG = -mthumb -mcpu=cortex-m4
RF_KERNEL_DIR = ${CUR_DIR}/../../kernel
CMSIS_CORE_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Include/
CMSIS_STM32F4XX_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Include/
CMSIS_STARTUP_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Source/Templates/gcc
CMSIS_SYSTEM_CONFIG_INC_PATH = /home/wookie/Development/ARMDev/src/lib/CMSIS/Device/ST/STM32F4xx/Source/Templates
CFLAGS = -I ${CMSIS_CORE_INC_PATH} -I ${CMSIS_STM32F4XX_INC_PATH} -I${RF_KERNEL_DIR}
LINKER_SCRIPT = STM32F407VGTx_FLASH.ld
LINKER_PATH = /home/wookie/Development/ARMDev/src/lib/STM32F407_Linker/
LFLAGS = -T ${LINKER_SCRIPT} -L ${LINKER_PATH}

INCLUDE_DIRS = -I./
INCLUDE_DIRS +=  -I../../components/LEDManager/
INCLUDE_DIRS += -I../../system/
INCLUDE_DIRS += -I../../kernel/

DEPENDENCIES = ../../components/LEDManager/fakeLED.o

KERNEL_OBJS = ${RF_KERNEL_DIR}/RF_queue.o
KERNEL_OBJS += ${RF_KERNEL_DIR}/RF_events.o
KERNEL_OBJS += ${RF_KERNEL_DIR}/RF_scheduler.o
KERNEL_OBJS += ${RF_KERNEL_DIR}/RF_dispatcher.o
KERNEL_OBJS += ${RF_KERNEL_DIR}/RF_agents.o



ARM_main: ${DEPENDENCIES}
	${CC_TARGET} ${CC_CONFIG} ${CPU_CONFIG} -Os \
	${CFLAGS} ${INCLUDE_DIRS} ${LFLAGS} ${CMSIS_STARTUP_INC_PATH}/startup_stm32f407xx.s \
	${DEPENDENCIES} ARM_main.c ${CMSIS_SYSTEM_CONFIG_INC_PATH}/system_stm32f4xx.c -o ARM_main.axf;
	arm-none-eabi-objcopy -O binary ARM_main.axf ARM_main.bin
	
build_synthetic: ../../components/LEDManager/LEDManager.o ${KERNEL_OBJS} 
	${CC_SYNTHETIC} -g -Wall ${CFLAGS} ${INCLUDE_DIRS} ../../components/LEDManager/LEDManager.o \
	${KERNEL_OBJS} ARM_main_synth.c -o ARM_main
	
clean:
	rm -rf *~ *.axf *.bin ARM_main