#include <stdio.h>
#include <stdlib.h>

#define N 10

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i];
    }

    printf("sum %d\n", sum);
    return 0;
}
