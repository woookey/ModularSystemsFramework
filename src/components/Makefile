CUR_DIR = $(shell pwd)

build_components:
	cd ${CUR_DIR}/LEDManager; make LEDManager CC=${CC}
	
test_components:
	make test_components_LEDManager
	
test_components_LEDManager:
	cd ${CUR_DIR}/LEDManager; make test CC=gcc

clean:
	cd $(CUR_DIR)/LEDManager; make clean
	
#include LEDManager/Makefile