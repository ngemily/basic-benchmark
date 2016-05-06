#include <stdio.h>
#include <stdlib.h>

#define N 100

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += A[(i + j) % 10];
        }
    }

    printf("sum %d\n", sum);
    return 0;
}
