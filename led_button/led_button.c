/*
 * =====================================================================================
 *
 *       Filename:  led6.c
 *
 *    Description:  turn on the activity led on the board when the button is pushed (PIN 29) and then after about 7 seconds blink the led on pin 31 rapidly
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

#define SLEEP           30000

extern void wait(int);

/** Main function - we'll never return from here */
int gogo(void)
{
    unsigned int i = 0;
    unsigned int j;
    /* Assign the address of the GPIO peripheral (Using ARM Physical Address) */

    GPIO_setoutput(47);
    GPIO_setinput(PIN_29);
    while (1){
        if (GPIO_getlevel(PIN_29) > 0){
            i++;
            if (i > 1000000){
                GPIO_setoutput(PIN_31);
                for (j=0; j<SLEEP; j++) wait(j);
                GPIO_clearoutput(PIN_31);
                for (j=0; j<SLEEP; j++) wait(j);
            }
            GPIO_setpin(47);
        } else {
            i = 0;
            GPIO_clearoutput(PIN_31);
            GPIO_clearpin(47);
        }
    }
}
