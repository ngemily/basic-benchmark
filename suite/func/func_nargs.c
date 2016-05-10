#include <stdio.h>
#include <stdlib.h>

void __attribute__ ((noinline)) foo() {
    printf("foobar\n");
}

int main(int argc, char *argv[]) {
    foo();
    return 0;
}
