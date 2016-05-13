/**
 * Function pointers
 *
 * Exercise conditional function pointer assignment.  Uses blx instruction to
 * change PC to value stored in register.
 */
#include <stdio.h>
#include <stdlib.h>

volatile int x = 1;

void __attribute__ ((noinline)) bar() {
    puts("bar");
}

void __attribute__ ((noinline)) foo() {
    puts("foo");
}

int main(int argc, char *argv[]) {
    void (*fp)() = x ? foo : bar;
    fp();
    return 0;
}
