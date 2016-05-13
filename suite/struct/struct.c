#include <stdio.h>
#include <stdlib.h>

struct point {
    int x;
    int y;
};

volatile struct point p = {.x = 1, .y = 1};

int main(int argc, char *argv[]) {
    printf("%d %d\n", p.x, p.y);
    return 0;
}
