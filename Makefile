DEV_DIR = /home/wookie/Development/ARMDev
CUR_DIR = $(shell pwd)
KERNEL_DIR = ${CUR_DIR}/src/kernel
TARGET_BUILD = ${CUR_DIR}/src/target/discoveryf4
COMPONENTS_DIR = ${CUR_DIR}/src/components


all:
	make build_kernel
	make test_kernel

build_target:
	cd ${COMPONENTS_DIR}; make build_components_target
	cd ${TARGET_BUILD}; make ARM_main
	mkdir -p bld/target
	cp ${TARGET_BUILD}/ARM_main.axf ${CUR_DIR}/bld/target
	cp ${TARGET_BUILD}/ARM_main.bin ${CUR_DIR}/bld/target

build_kernel:
	cd ${KERNEL_DIR}; make main
	mkdir -p bld/
	cp ${KERNEL_DIR}/main ${CUR_DIR}/bld
	
test_kernel:
	cd ${KERNEL_DIR}; make test
	
build_LEDManager_synthetic:
	cd ${COMPONENTS_DIR}; make LEDManager_synthetic

clean:
	rm -rf bld
	cd ${KERNEL_DIR}; make clean
	cd ${TARGET_BUILD}; make clean
	cd ${COMPONENTS_DIR}; make clean