CUR_DIR = $(shell pwd)

build_components:
	make build_components_CP_HA_LED
	make build_components_CP_HD_LEDDriver
	make build_components_LEDManager
	
build_components_CP_HA_LED:
	cd ${CUR_DIR}/CP_HA_LED; make CP_HA_LED.o CC=${CC}

build_components_CP_HD_LEDDriver:
	cd ${CUR_DIR}/CP_HD_LEDDriver; make CP_HD_LEDDriver.o CC=${CC}
	
build_components_LEDManager:
	cd ${CUR_DIR}/LEDManager; make LEDManager.o CC=${CC}
	
test_components:
	make test_components_LEDManager
	make test_components_CP_HD_LEDDriver
	
test_components_LEDManager:
	cd ${CUR_DIR}/LEDManager; make test #TODO: Enable LEDManager unit tests
	
test_components_CP_HD_LEDDriver:
	cd ${CUR_DIR}/CP_HD_LEDDriver; make test

clean:
	cd $(CUR_DIR)/LEDManager; make clean
	cd ${CUR_DIR}/CP_HD_LEDDriver; make clean
	cd ${CUR_DIR}/CP_HA_LED; make clean