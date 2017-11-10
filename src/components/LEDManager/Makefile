CUR_DIR = $(shell pwd)
KERNEL_DIR = ${CUR_DIR}/../../kernel
#CC_SYNTHETIC = gcc
#CC_TARGET = arm-none-eabi-gcc
CFLAGS = -Wall -g -I. -c 
INCLUDE_DIR = -I${KERNEL_DIR}

test: LEDManager.o
	cd ${CUR_DIR}/tests; make test

LEDManager.o: LEDManager.c LEDManager.h ${KERNEL_DIR}/RF_agents.o ${KERNEL_DIR}/RF_events.o ${KERNEL_DIR}/RF_queue.o
	${CC} ${CFLAGS} ${INCLUDE_DIR} LEDManager.c

clean:
	rm -rf *.o *~
	cd ${CUR_DIR}/tests; make clean