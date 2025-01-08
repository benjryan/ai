#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    size_t rows;
    size_t cols;
    float *p;
} Matrix;

#define matrix_at(m, i, j) m.p[(m).cols*(i)+(j)]
Matrix matrix_alloc(size_t rows, size_t cols);
void matrix_fill(Matrix m, float x);
void matrix_sum(Matrix dst, Matrix m);
void matrix_dot(Matrix dst, Matrix a, Matrix b);
void matrix_print(Matrix m);
void matrix_rand(Matrix m, float low, float high);

float rand_float(void);

#ifdef NN_IMPLEMENTATION

Matrix matrix_alloc(size_t rows, size_t cols) {
    Matrix dst = {};
    dst.rows = rows;
    dst.cols = cols;
    dst.p = malloc(sizeof(*dst.p)*rows*cols);
    assert(dst.p != NULL);
    return dst;
}

void matrix_fill(Matrix m, float x) {
    for (size_t i = 0; i < m.rows; ++i) {
        for (size_t j = 0; j < m.cols; ++j) {
            matrix_at(m, i, j) = x;
        }
    }
}

void matrix_sum(Matrix dst, Matrix m) {
    assert(dst.rows == m.rows);
    assert(dst.cols == m.cols);
    for (size_t i = 0; i < dst.rows; ++i) {
        for (size_t j = 0; j < dst.cols; ++j) {
            matrix_at(dst, i, j) += matrix_at(m, i, j);
        }
    }
}

void matrix_dot(Matrix dst, Matrix a, Matrix b) {
    assert(a.cols == b.rows);
    size_t n = a.cols;
    assert(dst.rows == a.rows);
    assert(dst.cols == b.cols);

    for (size_t i = 0; i < dst.rows; ++i) {
        for (size_t j = 0; j < dst.cols; ++j) {
            matrix_at(dst, i, j) = 0;
            for (size_t k = 0; k < n; ++k) {
                matrix_at(dst, i, j) += matrix_at(a, i, k)*matrix_at(b, k, j);
            }
        }
    }
}

void matrix_print(Matrix m) {
    for (size_t i = 0; i < m.rows; ++i) {
        for (size_t j = 0; j < m.cols; ++j) {
            printf("%f ", matrix_at(m, i, j));
        }
        printf("\n");
    }
}

void matrix_rand(Matrix m, float low, float high) {
    for (size_t i = 0; i < m.rows; ++i) {
        for (size_t j = 0; j < m.cols; ++j) {
            matrix_at(m, i, j) = rand_float()*(high-low) + low;
        }
    }
}

float rand_float(void) {
    return (float)rand() / (float)RAND_MAX;
}

#endif
