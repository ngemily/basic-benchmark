#include <stdio.h>
#include <stdlib.h>

#define N 10

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(int argc, char *argv[]) {
    int n;
    if (A[0]) {
        puts("a");
        n = A[0];
    }
    else {
        puts("c");
        n = A[2];
    }
    printf("%d\n", n);
    return 0;
}
