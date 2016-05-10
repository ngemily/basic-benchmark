#include <stdio.h>
#include <stdlib.h>

volatile float x = 1;

float __attribute__ ((noinline)) foo() {
    return x;
}

int main(int argc, char *argv[]) {
    volatile float x = foo();
    printf("%f\n", x);
    return 0;
}
