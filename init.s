.globl _start
_start:
    mov sp, #0x8000
    bl  gogo
hang:
    b hang
