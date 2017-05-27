CUR_DIR = $(shell pwd)

build_components_target:
	make LEDManager_target
	
LEDManager_synthetic:
	cd $(CUR_DIR)/LEDManager; make build_synthetic
	
LEDManager_target:
	cd $(CUR_DIR)/LEDManager; make build_target

clean:
	cd $(CUR_DIR)/LEDManager; make clean