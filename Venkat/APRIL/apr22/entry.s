.secton .text
.globl _start

_start:
call printf_hello_world
mov $1, %eax    #exit system call
xor %ebx, %ebx  #exit status 0
int $0x80     #invoke kernel
