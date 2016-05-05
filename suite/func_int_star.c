#include <stdio.h>
#include <stdlib.h>

int A = 1;

int *foo() {
    return &A;
}

int main(int argc, char *argv[]) {
    int *p = foo();
    printf("%d\n", *p);
    return 0;
}
