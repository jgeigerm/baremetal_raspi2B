/*
 * =====================================================================================
 *
 *       Filename:  testout.c
 *
 *    Description:  used to determine what gpio numbers go with which pins
 *                  counts from 1 to 35. Blinks 3 times slow, then twice fast
 *                  to signify the next number. You can just count up and when
 *                  the pin you are looking for goes on and off 3 times you
 *                  have found it's GPIO number!
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

#define SLEEP           200000

extern void wait(int);

/** Main function - we'll never return from here */
int gogo(void)
{
    unsigned int i;
    unsigned int j;
    /* Assign the address of the GPIO peripheral (Using ARM Physical Address) */

    GPIO_setoutput(47);
    for (j=3; j<35;j++){
        GPIO_setoutput(j);
        GPIO_clearpin(j);
        GPIO_clearpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_setpin(j);
        GPIO_setpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_clearpin(j);
        GPIO_clearpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_setpin(j);
        GPIO_setpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_clearpin(j);
        GPIO_clearpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_setpin(j);
        GPIO_setpin(47);
        for (i=0; i<SLEEP; i++) wait(i);
        GPIO_clearpin(j);
        for (i=0; i<50000; i++) wait(i);
        GPIO_clearpin(47);
        for (i=0; i<50000; i++) wait(i);
        GPIO_setpin(47);
        for (i=0; i<50000; i++) wait(i);
        GPIO_clearpin(47);
        for (i=0; i<50000; i++) wait(i);
        GPIO_setpin(47);
        GPIO_clearoutput(j);
    }
}
