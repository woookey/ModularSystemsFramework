DEV_DIR = /home/wookie/Development/ARMDev

build_kernel:
	cd ${DEV_DIR}/src/kernel; make 

clean:
	rm -rf bld
	cd ${DEV_DIR}/src/kernel; make clean