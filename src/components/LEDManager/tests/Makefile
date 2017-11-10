CUR_DIR = $(shell pwd)
UNITY_DIR = ${CUR_DIR}/../../../testing/Unity
LED_MANAGER_DIR = ${CUR_DIR}/..
KERNEL_DIR = ${CUR_DIR}/../../../kernel
SYSTEM_DIR = ${CUR_DIR}/../../../system
PORT_DIR = ${CUR_DIR}/../../../porting/synthetic

KERNEL_OBJS = ${KERNEL_DIR}/RF_scheduler.o ${KERNEL_DIR}/RF_dispatcher.o
KERNEL_OBJS += ${KERNEL_DIR}/RF_queue.o ${KERNEL_DIR}/RF_events.o 
KERNEL_OBJS += ${KERNEL_DIR}/RF_agents.o

OBJS = test.c ${UNITY_DIR}/unity.c ${PORT_DIR}/porting.c ${LED_MANAGER_DIR}/LEDManager.c

INC_DIR = -I. -I${UNITY_DIR} -I${LED_MANAGER_DIR} -I${KERNEL_DIR} -I${SYSTEM_DIR}
INC_DIR += -I${PORT_DIR}

CC = gcc
CFLAGS = -Wall -g -I. -I${UNITY_DIR}
 
test: 
	make CP_LEDManager_UnitTest
	./CP_LEDManager_UnitTest

CP_LEDManager_UnitTest: ${OBJS} ${LED_MANAGER_DIR}/LEDManager.o ${KERNEL_OBJS} 
	${CC} ${CFLAGS} ${INC_DIR} ${OBJS} ${KERNEL_OBJS} -o CP_LEDManager_UnitTest
	
clean:
	rm -rf *.o *~
	rm -rf CP_LEDManager_UnitTest