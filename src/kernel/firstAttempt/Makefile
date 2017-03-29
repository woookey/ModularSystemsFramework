OBJS = AgentExperiment.o AgentLogger.o main.o ObjectsManager.o
CC = gcc
CFLAGS = -Wall -c -I.
LFLAGS = -Wall 
#INC_DIR = -I./

all: AgentExperiment.o main.o AgentLogger.o
	${CC} ${LFLAGS} ${OBJS} -o main
	
main.o: AgentExperiment.o AgentLogger.o main.c
	${CC} ${CFLAGS} main.c
 
AgentExperiment.o: AgentExperiment.c AgentExperiment.h ObjectsManager.o
	 ${CC} ${CFLAGS} AgentExperiment.c
	 
AgentLogger.o: AgentLogger.c AgentLogger.h ObjectsManager.o
	${CC} ${CFLAGS} AgentLogger.c

ObjectsManager.o: ObjectsManager.c SignalSpace.h ObjectsManager.h
	${CC} ${CFLAGS} ObjectsManager.c

clean:
	rm -rf *.o *~ main