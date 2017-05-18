RF_DIR = ${HOME}/Development/ARMDev/src/kernel
UNITY_DIR = ${HOME}/Development/ARMDev/src/testing/Unity
RF_OBJS = RF_timers.o RF_events.o RF_agents.o
OBJS = test.o unity.o
CC = gcc
CFLAGS = -Wall -g -I${RF_DIR} -I${UNITY_DIR} -c 
LFLAGS = -Wall -g -I. -I${RF_DIR}

test:
	make RF_timersUnitTest
	./RF_timers_UnitTest

RF_timersUnitTest: ${OBJS} ${RF_OBJS}
	${CC} ${LFLAGS} ${OBJS} ${RF_OBJS} -o RF_timers_UnitTest
	
unity.o: ${UNITY_DIR}/unity.c ${UNITY_DIR}/unity.h
	${CC} ${CFLAGS} ${UNITY_DIR}/unity.c 
	
test.o: test.c
	${CC} ${CFLAGS} test.c

RF_timers.o: ${RF_DIR}/RF_timers.c ${RF_DIR}/RF_timers.h ${RF_DIR}/RF_agents.o ${RF_DIR}/RF_events.o
	${CC} ${CFLAGS} ${RF_DIR}/RF_timers.c
	
RF_agents.o: ${RF_DIR}/RF_agents.c ${RF_DIR}/RF_agents.h ${RF_DIR}/RF_events.o ${RF_DIR}/RF_queue.o
	${CC} ${CFLAGS} ${RF_DIR}/RF_agents.c
	
RF_events.o: ${RF_DIR}/RF_events.c ${RF_DIR}/RF_events.h
	${CC} ${CFLAGS} ${RF_DIR}/RF_events.c

clean:
	rm -rf *.o *~ RF_timers_UnitTest
