/*
 * =====================================================================================
 *
 *       Filename:  led6.c
 *
 *    Description:  blink an LED on GPIO 6
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
#include "../raspi.h"

#define SLEEP           300000

extern void wait(int);

/** Main function - we'll never return from here */
int gogo(void)
{
    unsigned int i;
    unsigned int j;
    /* Assign the address of the GPIO peripheral (Using ARM Physical Address) */

    GPIO_setoutput(47);
    GPIO_setoutput(PIN_29);
    while (1){
        GPIO_setoutput(PIN_31);
        GPIO_clearpin(PIN_29);
        GPIO_clearpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_clearoutput(PIN_31);
        GPIO_setpin(PIN_29);
        GPIO_setpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
    }
}
