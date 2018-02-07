CUR_DIR = $(shell pwd)

OBJS = CP_HD_LEDDriver.c

CFLAGS = -Wall -g -I. -c

INC_DIR = -I${CUR_DIR}/../CP_HA_LED/

ifeq (${GCC}, gcc)
	INC_DIR += -I${CUR_DIR}/../CP_HA_LED/target/ 
else
	INC_DIR += -I${CUR_DIR}/../CP_HA_LED/synthetic/
endif

CP_HD_LEDDriver.o: CP_HD_LEDDriver.c
	${CC} ${CFLAGS} ${INC_DIR} ${OBJS} -o CP_HD_LEDDriver.o
	
clean:
	rm -rf *.o *.~