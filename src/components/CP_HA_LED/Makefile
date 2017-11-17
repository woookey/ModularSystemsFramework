CUR_DIR = $(shell pwd)
CFLAGS = -Wall -g -c -I.

#HAL_DRIVER_SRC = ${CUR_DIR}/../../lib/STM32F4xx_HAL_Driver/Src

ifeq ( ${CC}, gcc )
	INC_DIR = -I${CUR_DIR}/synthetic
	OBJS = ${CUR_DIR}/synthetic/CP_HA_LED.c
else
	INC_DIR = -I${CUR_DIR}/target
	INC_DIR += -I${CUR_DIR}/../../lib/STM32F4xx_HAL_Driver/Inc
	INC_DIR += -I${CUR_DIR}/../../lib/CMSIS/Device/ST/STM32F4xx/Include
	INC_DIR += -I${CUR_DIR}/../../lib/CMSIS/Include
	CFLAGS += -DSTM32F407xx
	OBJS = ${CUR_DIR}/target/CP_HA_LED.c
	#OBJS += ${HAL_DRIVER_SRC}/stm32f4xx_hal_gpio.o
endif

CP_HA_LED.o: ${OBJS} #${HAL_DRIVER_SRC}/stm32f4xx_hal_gpio.o
	#${CC} ${CFLAGS} -I${INC_DIR} ${HAL_DRIVER_SRC}/stm32f4xx_hal_gpio.c -o stm32f4xx_hal_gpio.o;
	${CC} ${CFLAGS} ${INC_DIR} ${OBJS} -o CP_HA_LED.o
	
${HAL_DRIVER_SRC}/stm32f4xx_hal_gpio.o:
	${CC} ${CFLAGS} ${INC_DIR} ${HAL_DRIVER_SRC}/stm32f4xx_hal_gpio.c -o stm32f4xx_hal_gpio.o
clean:
	rm -rf *.o *.~ 