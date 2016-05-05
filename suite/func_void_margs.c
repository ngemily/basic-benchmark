#include <stdio.h>
#include <stdlib.h>

void foo(int x, int y, int z, int u, int v, int w) {
    printf("foobar\n");
}

int main(int argc, char *argv[]) {
    foo(1, 2, 3, 4, 5, 6);
    return 0;
}
