#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int x=1, z;
    asm(
            "mov %[b], %[a]\n\t"
            "mov %[b], #2"
            : [b] "=r" (z)
            : [a] "r" (x)
       );
    printf("z %d\n", z);
    
    return 0;
}
