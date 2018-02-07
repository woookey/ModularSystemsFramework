CUR_DIR = $(shell pwd)

OBJS = CP_HD_LEDDriver.c

CFLAGS = -Wall -g -I. -c

INC_DIR = -I${CUR_DIR}/../CP_HA_LED/

ifeq (${CC}, arm-none-eabi-gcc)
	INC_DIR += -I${CUR_DIR}/../CP_HA_LED/target/ 
	INC_DIR += -I${CUR_DIR}/../../lib/CMSIS/Device/ST/STM32F4xx/Include
	INC_DIR += -I${CUR_DIR}/../../lib/CMSIS/Include
	INC_DIR += -I${CUR_DIR}/../../lib/STM32F4xx_HAL_Driver/Inc
	CFLAGS += -DSTM32F407xx
else
	INC_DIR += -I${CUR_DIR}/../CP_HA_LED/synthetic/
endif

CP_HD_LEDDriver.o: CP_HD_LEDDriver.c
	${CC} ${CFLAGS} ${INC_DIR} ${OBJS} -o CP_HD_LEDDriver.o
	
clean:
	rm -rf *.o *.~