#include <stdio.h>
#include <stdlib.h>

volatile int x = 1;

int __attribute__ ((noinline)) foo() {
    return x;
}

int main(int argc, char *argv[]) {
    volatile int x = foo();
    printf("%d\n", x);
    return 0;
}
