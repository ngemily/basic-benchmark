#include <stdio.h>
#include <stdlib.h>

int a = 8;

void __attribute__ ((noinline)) foo(int *p) {
    *p = 8;
}

int main(int argc, char *argv[]) {
    int p;
    foo(&p);
    printf("p %d\n", p);
    return 0;
}
