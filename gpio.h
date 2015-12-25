/*
 * =====================================================================================
 *
 *       Filename:  gpio.h
 *
 *    Description:  defines for pinouts and stuff
 *
 *        Version:  1.0
 *        Created:  12/24/2015 22:59:31
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Jaime Geiger (@jgeigerm), jmg2967@rit.edu
 *
 * =====================================================================================
 */

#ifndef GPIO_H
#define GPIO_H
/* this is the base for the Raspi 2 Model B */
#define GPIO_BASE       0x3F200000UL

/* Function selects
 * 3 byte increments starting at 0
 * each commented number indicates the GPIO pins that are controlled
 * possible values:
 * 000 = input
 * 001 = output
 * 100 = alt function 0
 * 101 = alt function 1
 * 110 = alt function 2
 * 111 = alt function 3
 * 011 = alt function 4
 * 010 = alt function 5
 */
#define GPFSEL0         0 /* 0-9   */
#define GPFSEL1         1 /* 10-19 */
#define GPFSEL2         2 /* 20-29 */
#define GPFSEL3         3 /* 30-39 */
#define GPFSEL4         4 /* 40-49 */
#define GPFSEL5         5 /* 50-53 */

/* Output set, clear, and level registers
 * Set to 1 to set/clear GPIO pin at that bit
 * *(GPIO_BASE + GPSET0*sizeof(int)) = (1 << 12) sets the 12th GPIO pin.
 */
#define GPSET0          7  /* 0-31  */
#define GPSET1          8  /* 32-53 */
#define GPCLR0          10 /* 0-31  */
#define GPCLR1          11 /* 32-53 */
#define GPLVL0          13 /* 0-31  */
#define GPLVL1          14 /* 32-53 */

/* Helper functions */

void GPIO_setpin(uint32_t pin);
void GPIO_clearpin(uint32_t pin);
void GPIO_setoutput(uint32_t pin);
void GPIO_clearoutput(uint32_t pin);
void GPIO_setinput(uint32_t pin);
unsigned int GPIO_getlevel(uint32_t pin);
#endif
