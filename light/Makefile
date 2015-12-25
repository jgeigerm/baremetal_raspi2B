GCC = arm-none-eabi
all: light

light: clean common
	$(GCC)-gcc -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles -c $@.c
	$(GCC)-ld ../init.o ../gpio.o ../helpers.o $@.o -o $@.elf
	$(GCC)-objcopy $@.elf -O binary $@.img

common:
	make -C ../

copy: light
	cp light.img /Volumes/DAD/kernel.img

clean:
	make clean -C ../
	rm -rf *.o *.elf *.img 2>/dev/null
