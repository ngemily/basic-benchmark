#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x, z=1;
    asm(
            "mov %[b], %[a]\n\t"
            "mov %[a], #2"
            : [b] "=r" (x)
            : [a] "r" (z)
       );
    printf("x %d\n", x);
    
    return 0;
}
