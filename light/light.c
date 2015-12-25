/*
 * =====================================================================================
 *
 *       Filename:  light.c
 *
 *    Description:  blink a light on the board
 *
 *        Version:  1.0
 *        Created:  12/23/2015 00:29:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jaime Geiger (@jgeigerm), jmg2967@rit.edu
 *
 * =====================================================================================
 */

#include <stdint.h>
#include "../gpio.h"

#define SLEEP           750000

extern void wait(int);

/** GPIO Register set */
volatile uint32_t* gpio;

/** Main function - we'll never return from here */
int gogo(void)
{
    unsigned int i;
    /* Assign the address of the GPIO peripheral (Using ARM Physical Address) */

    /* Write 1 to the GPIO16 init nibble in the Function Select 1 GPIO
       peripheral register to enable GPIO16 as an output */
    GPIO_setoutput(47);
    while (1){
        GPIO_setpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_clearpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
    }
}
