GCC = arm-none-eabi
all: gpio init helpers

gpio:
	$(GCC)-gcc -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles -c $@.c

init:
	$(GCC)-as -o init.o init.s

helpers:
	$(GCC)-as -o helpers.o helpers.s

clean:
	rm -rf *.o *.elf *.img 2>/dev/null
