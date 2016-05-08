#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    asm ("add r2, r1, r0");

    return 0;
}
