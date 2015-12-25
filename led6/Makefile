GCC = arm-none-eabi
all: led6

led6: clean common
	$(GCC)-gcc -O2 -mfpu=neon-vfpv4 -mfloat-abi=hard -march=armv7-a -mtune=cortex-a7 -nostartfiles -c $@.c
	$(GCC)-ld ../init.o ../gpio.o ../helpers.o $@.o -o $@.elf
	$(GCC)-objcopy $@.elf -O binary $@.img

common:
	make -C ../

copy: led6
	cp led6.img /Volumes/DAD/kernel.img

clean:
	make clean -C ../
	rm -rf *.o *.elf *.img 2>/dev/null
