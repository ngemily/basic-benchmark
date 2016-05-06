#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    volatile int x = 1;
    volatile int y = 1;
    volatile int z;

    z = x + y;
    z = x + 4;

    return 0;
}
