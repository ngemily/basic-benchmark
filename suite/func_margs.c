#include <stdio.h>
#include <stdlib.h>

void foo(int x, int y, int z, int u, int v, int w, int a, int b, int c) {
    int sum = x + y + z + u + v + w + a + b + c;
    printf ("sum %d\n", sum);
}

int main(int argc, char *argv[]) {
    foo(1, 2, 3, 4, 5, 6, 7, 8, 9);
    return 0;
}
