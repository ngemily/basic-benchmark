#include <stdio.h>
#include <stdlib.h>

volatile long long x = 1;

long long __attribute__ ((noinline)) foo() {
    return x;
}

int main(int argc, char *argv[]) {
    volatile long long x = foo();
    printf("%llu\n", x);
    return 0;
}
