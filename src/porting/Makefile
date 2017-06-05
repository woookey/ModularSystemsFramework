CUR_DIR = ${shell pwd}
KERNEL_DIR = ../kernel
CFLAGS = -Wall -g -c
INCLUDE_DIR = -I${KERNEL_DIR}

ifeq (${CC}, arm-none-eabi-gcc)
	BUILD_DIR = ${CUR_DIR}/stm32f4
else
	BUILD_DIR = ${CUR_DIR}/synthetic
endif

build_porting: ${KERNEL_DIR}/RF_porting.h
	${CC} ${CFLAGS} ${INCLUDE_DIR} ${BUILD_DIR}/porting.c
	
clean:
	rm -rf *.o *~