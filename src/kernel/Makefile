RF_OBJS = RF_agents.o RF_scheduler.o RF_events.o RF_queue.o RF_dispatcher.o
OBJS = main.o LEDManagerTest.o
CFLAGS = -Wall -g -I. -c
LFLAGS = -Wall -I.
CC = gcc
CC_TARGET = arm-none-eabi-gcc

RF_kernel: ${RF_OBJS}

RF_scheduler.o: RF_agents.o RF_scheduler.h RF_scheduler.c RF_events.o RF_queue.o RF_porting.h
	${CC} ${CFLAGS} RF_scheduler.c
	
RF_dispatcher.o: RF_agents.o RF_queue.o RF_events.o RF_dispatcher.h RF_dispatcher.c RF_definitions.h RF_porting.h
	${CC} ${CFLAGS} RF_dispatcher.c

RF_timers.o: RF_timers.c RF_timers.h RF_agents.o RF_events.o RF_porting.h
	${CC} ${CFLAGS} RF_timers.c

RF_agents.o: RF_agents.c RF_agents.h RF_events.o RF_queue.o
	${CC} ${CFLAGS} RF_agents.c
	
RF_queue.o: RF_events.o RF_queue.c RF_queue.h
	${CC} ${CFLAGS} RF_queue.c
	
RF_events.o: RF_events.c RF_events.h
	${CC} ${CFLAGS} RF_events.c
	
test:
	cd tests/queue; make test
	cd tests/dispatcher; make test
	cd tests/timers; make test
	
clean:
	rm -rf *.o *~ main
	cd tests/queue; make clean
	cd tests/dispatcher; make clean
	cd tests/timers; make clean
	
