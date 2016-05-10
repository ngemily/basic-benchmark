#include <stdio.h>
#include <stdlib.h>

volatile short x = 1;

short __attribute__ ((noinline)) foo() {
    return x;
}

int main(int argc, char *argv[]) {
    volatile short x = foo();
    printf("%d\n", x);
    return 0;
}
