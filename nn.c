#include <time.h>

#define NN_IMPLEMENTATION
#include "nn.h"

int main() {
    srand(time(0));

    Matrix a = matrix_alloc(1, 2);
    matrix_rand(a, 5, 10);

    Matrix b = matrix_alloc(2, 2);
    matrix_fill(b, 0);

    Matrix dst = matrix_alloc(1, 2);

    matrix_print(a);
    printf("--------------------\n");
    matrix_dot(dst, a, b);
    matrix_print(dst);

    return 0;
}
