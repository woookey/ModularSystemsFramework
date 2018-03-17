# ARMDev
## Compilation ##
make build_target - for target 
make build_synthetic - for synthetic

## Testing ##
make test

## Running synthetic version ##
./bld/synthetic/ARM_main_synth

## Flashing target ##
st-flash write ./bld/target/ARM_main_stm32.bin 0x8000000
