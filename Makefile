DEV_DIR = /home/wookie/Development/ARMDev
KERNEL_DIR = ${DEV_DIR}/src/kernel

build_kernel:
	cd ${KERNEL_DIR}; make main
	mkdir -p bld/
	cp ${KERNEL_DIR}/main ${DEV_DIR}/bld
	
test_kernel:
	cd ${KERNEL_DIR}; make test

clean:
	rm -rf bld
	cd ${KERNEL_DIR}; make clean