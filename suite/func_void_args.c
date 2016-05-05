#include <stdio.h>
#include <stdlib.h>

void foo(int n) {
    printf("foobar %d\n", n);
}

int main(int argc, char *argv[]) {
    foo(1);
    return 0;
}
