#include <stdio.h>
#include <stdlib.h>

void __attribute__ ((noinline)) foo(int n) {
    printf("%d\n", n);
}

int main(int argc, char *argv[]) {
    foo(1);
    return 0;
}
