#include <stdio.h>
#include <stdlib.h>

int* __attribute__ ((noinline)) foo() {
    int *p = (int *)(malloc(sizeof(int)));
    *p = 1;
    return p;
}

int main(int argc, char *argv[]) {
    int *p = foo();
    printf("%d\n", *p);
    free(p);
    return 0;
}
