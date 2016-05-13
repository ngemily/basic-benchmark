/**
 * Pointers
 *
 * Exercise conditional pointer assignment, then use that pointer.
 */
#include <stdio.h>
#include <stdlib.h>

#define N 10

volatile int x = 1;
int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int B[10] = {11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

int main(int argc, char *argv[]) {
    int sum = 0;
    int *arr = x ? A : B;

    for (int i = 0; i < N; i++) {
        sum += arr[i];
    }

    printf("sum %d\n", sum);
    return 0;
}
