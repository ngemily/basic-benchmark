#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x=1, y=1, z;
    asm(
            "add %[c], %[a], %[b]\n\t"
            "add %[c], %[c], #1"
            : [c] "=r" (z)
            : [a] "r" (x), [b] "r" (y)
            );

    printf("z %d\n", z);
    return 0;
}
