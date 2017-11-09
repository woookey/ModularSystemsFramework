CUR_DIR = $(shell pwd)
UNITY_DIR = ${CUR_DIR}/../../../testing/Unity
LED_MANAGER_DIR = ${CUR_DIR}/..
KERNEL_DIR = ${CUR_DIR}/../../../kernel
OBJS = test.c ${UNITY_DIR}/unity.c
INC_DIR = -I. -I${UNITY_DIR} -I${LED_MANAGER_DIR} -I${KERNEL_DIR}
CC = gcc
CFLAGS = -Wall -g -I. -I${UNITY_DIR}
 
test: 
	make CP_LEDManager_UnitTest
	./CP_LEDManager_UnitTest

CP_LEDManager_UnitTest: ${UNITY_DIR}/unity.c ${LED_MANAGER_DIR}/LEDManager.o
	${CC} ${CFLAGS} -I${INC_DIR} ${OBJS} -o CP_LEDManager_UnitTest
	
clean:
	rm -rf *.o *~
	rm -rf CP_LEDManager_UnitTest