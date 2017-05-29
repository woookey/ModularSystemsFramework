CUR_DIR = $(shell pwd)
KERNEL_DIR = ${CUR_DIR}/../../kernel
CC_SYNTHETIC = gcc
CC_TARGET = arm-none-eabi-gcc
CFLAGS = -Wall -g -I. -c 
INCLUDE_DIR = -I${KERNEL_DIR}


build_synthetic: 
	make clean
	${CC_SYNTHETIC} ${CFLAGS} fakeLED.c 
	
build_target:
	make clean
	${CC_TARGET} ${CFLAGS} fakeLED.c
	
build_synthetic_2: LEDManager.c LEDManager.h ${KERNEL_DIR}/RF_agents.o ${KERNEL_DIR}/RF_events.o ${KERNEL_DIR}/RF_queue.o
	make clean
	${CC_SYNTHETIC} ${CFLAGS} ${INCLUDE_DIR} LEDManager.c

clean:
	rm -rf *.o *~