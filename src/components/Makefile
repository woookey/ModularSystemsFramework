CUR_DIR = $(shell pwd)

build_components_target:
	make LEDManager_target
	
build_components_synthetic:
	make LEDManager_synthetic	

LEDManager_synthetic:
	cd $(CUR_DIR)/LEDManager; make build_synthetic_2
	
LEDManager_target:
	cd $(CUR_DIR)/LEDManager; make build_target

clean:
	cd $(CUR_DIR)/LEDManager; make clean