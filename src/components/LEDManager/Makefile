CC_SYNTHETIC = gcc
CC_TARGET = arm-none-eabi-gcc
CFLAGS = -Wall -g -I. -c 

#TODO: only target for build_synthetic at the moment - to be fixed
build_synthetic: fakeLED.o

build_target: fakeLED.o

fakeLED.o: fakeLED.h fakeLED.c
	${CC_TARGET} ${CFLAGS} fakeLED.c
	
clean:
	rm -rf *.o *~