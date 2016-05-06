#include <stdio.h>
#include <stdlib.h>

#define N 10

int A[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int foo(int i) {
    return (i % 2 == 0);
}

int main(int argc, char *argv[]) {
    int n = (A[0]) ? A[0] :
            (A[1]) ? A[1] :
            (A[2]) ? A[2] :
            (A[3]) ? A[3] :
            (A[4]) ? A[4] :
            (A[5]) ? A[5] :
            (A[6]) ? A[6] :
            (A[7]) ? A[7] :
            (A[8]) ? A[8] :
                      A[9];

    printf("%d\n", n);
    return 0;
}
