RF_DIR = ${HOME}/Documents/ARMDev/src/kernel
RF_OBJS = RF_events.o RF_queue.o
OBJS = test.o
CC = gcc
CFLAGS = -Wall -g -I${RF_DIR} -c 
LFLAGS = -Wall -g -I.

all: ${OBJS} ${RF_OBJS} 
	${CC} ${LFLAGS} ${OBJS} ${RF_OBJS} -o test

test.o: test.c RF_queue.o RF_events.o
	${CC} ${CFLAGS} test.c

RF_queue.o: RF_events.o ${RF_DIR}/RF_queue.c ${RF_DIR}/RF_queue.h
	${CC} ${CFLAGS} ${RF_DIR}/RF_queue.c
	
RF_events.o: ${RF_DIR}/RF_events.c ${RF_DIR}/RF_events.h
	${CC} ${CFLAGS} ${RF_DIR}/RF_events.c

clean:
	rm -rf *.o *~ test
