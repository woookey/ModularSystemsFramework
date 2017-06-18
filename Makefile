DEV_DIR = /home/wookie/Development/ARMDev
CUR_DIR = $(shell pwd)
KERNEL_DIR = ${CUR_DIR}/src/kernel
TARGET_BUILD = ${CUR_DIR}/src/target/discoveryf4
COMPONENTS_DIR = ${CUR_DIR}/src/components
PORTING_DIR = ${CUR_DIR}/src/porting

build_synthetic:
	make clean
	cd ${KERNEL_DIR}; make RF_kernel
	cd ${PORTING_DIR}; make build_porting CC=gcc
	cd ${COMPONENTS_DIR}; make build_components CC=gcc
	cd ${TARGET_BUILD}; make build_synthetic
	mkdir -p bld/synthetic/
	cp ${TARGET_BUILD}/ARM_main_synth ${CUR_DIR}/bld/synthetic

build_target:
	make clean
	cd ${KERNEL_DIR}; make RF_kernel CC=arm-none-eabi-gcc
	cd ${PORTING_DIR}; make build_porting CC=arm-none-eabi-gcc
	cd ${COMPONENTS_DIR}; make build_components CC=arm-none-eabi-gcc
	cd ${TARGET_BUILD}; make build_target
	mkdir -p bld/target
	cp ${TARGET_BUILD}/ARM_main_stm32.axf ${CUR_DIR}/bld/target
	cp ${TARGET_BUILD}/ARM_main_stm32.bin ${CUR_DIR}/bld/target
	
build_sample_target:
	make clean
	cd ${KERNEL_DIR}; make RF_kernel CC=arm-none-eabi-gcc
	cd ${PORTING_DIR}; make build_porting CC=arm-none-eabi-gcc
	cd ${COMPONENTS_DIR}; make build_components CC=arm-none-eabi-gcc
	cd ${TARGET_BUILD}; make sample
	mkdir -p bld/target
	cp ${TARGET_BUILD}/sample.bin ${CUR_DIR}/bld/target

build_synthetic_kernel:
	make clean
	cd ${KERNEL_DIR}; make RF_kernel CC=gcc
	
test_kernel:
	make clean
	cd ${KERNEL_DIR}; make test
	
clean:
	rm -rf bld
	cd ${KERNEL_DIR}; make clean
	cd ${TARGET_BUILD}; make clean
	cd ${COMPONENTS_DIR}; make clean
	cd ${PORTING_DIR}; make clean