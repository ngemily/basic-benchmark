#include <stdio.h>
#include <stdlib.h>

#define N 100

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

/* Notes:
 *
 * sum += i gets the whole loop optimized away by constant folding
 * sum += A[i] is better, but a 10 element array gets the whole loop unrolled
 * sum += A[i % 10] lets the loop be longer without making A[] longer
 */

int main(int argc, char *argv[]) {
    int sum = 0;

    for (int i = 0; i < N; i++) {
        sum += A[i % 10];
    }

    printf("sum %d\n", sum);
    return 0;
}
