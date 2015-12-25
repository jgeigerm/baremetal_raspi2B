#include <stdint.h>
#include "gpio.h"

volatile unsigned int *gpio = (unsigned int*)GPIO_BASE;

void GPIO_setpin(uint32_t pin){
    if (pin <= 53)
        gpio[(pin > 31 ? 1 : 0) + GPSET0] = 1 << (pin % 32);
}

void GPIO_clearpin(uint32_t pin){
    if (pin <= 53)
        gpio[(pin > 31 ? 1 : 0) + GPCLR0] = 1 << (pin % 32);
}

void GPIO_setoutput(uint32_t pin){
    if (pin <= 53)
        gpio[pin/10] |= 1 << (pin % 10 * 3);
}

void GPIO_clearoutput(uint32_t pin){
    if (pin <= 53)
        gpio[pin/10 + GPFSEL0] &= ~(1 << (pin % 10 * 3));
}

void GPIO_setinput(uint32_t pin){
    if (pin <= 53)
        gpio[pin/10 + GPFSEL0] &= ~(7 << (pin % 10 * 3));
}

unsigned int GPIO_getlevel(uint32_t pin){
    if (pin <= 53)
        return (gpio[(pin > 31 ? 1 : 0) + GPLVL0] & (1 << (pin % 32))) >> (pin % 32);
    else
        return -1;
}
