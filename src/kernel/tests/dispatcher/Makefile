RF_DIR = ${HOME}/Development/ARMDev/src/kernel
UNITY_DIR = ${HOME}/Development/ARMDev/src/testing/Unity
RF_OBJS = ${RF_DIR}/RF_dispatcher.o ${RF_DIR}/RF_queue.o ${RF_DIR}/RF_events.o ${RF_DIR}/RF_agents.o
OBJS = test.o unity.o
CC = gcc
CFLAGS = -Wall -g -I${RF_DIR} -I${UNITY_DIR} -c 
LFLAGS = -Wall -g -I. -I${RF_DIR}

RF_dispatcherUnitTest: ${OBJS} ${RF_OBJS}
	${CC} ${LFLAGS} ${OBJS} ${RF_OBJS} -o RF_dispatcher_UnitTest
	
unity.o: ${UNITY_DIR}/unity.c ${UNITY_DIR}/unity.h
	${CC} ${CFLAGS} ${UNITY_DIR}/unity.c 
	
test.o: test.c
	${CC} ${CFLAGS} test.c

${RF_DIR}/RF_dispatcher.o: ${RF_DIR}/RF_dispatcher.c ${RF_DIR}/RF_dispatcher.h ${RF_DIR}/RF_queue.o ${RF_DIR}/RF_agents.o
	cd ${RF_DIR}; make RF_dispatcher.o
	
${RF_DIR}/RF_queue.o: ${RF_DIR}/RF_events.o ${RF_DIR}/RF_queue.c ${RF_DIR}/RF_queue.h
	${CC} ${CFLAGS} ${RF_DIR}/RF_queue.c
	
${RF_DIR}/RF_events.o: ${RF_DIR}/RF_events.c ${RF_DIR}/RF_events.h
	${CC} ${CFLAGS} ${RF_DIR}/RF_events.c

clean:
	rm -rf *.o *~ RF_dispatcher_UnitTest
