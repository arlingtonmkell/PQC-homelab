#include "lattice.h"

// Modular reduction
int mod_q(int a, int q) {
    while (a < 0) {
        a += q;
    }
    while (a >= q) {
        a -= q;
    }
    return a;
}

// Vector addition mod q
void vector_add(int *res, const int *a, const int *b, int length, int q) {
    for (int i = 0; i < length; i++) {
        res[i] = mod_q(a[i] + b[i], q);
    }
}

// Vector subtraction mod q
void vector_sub(int *res, const int *a, const int *b, int length, int q) {
    for (int i = 0; i < length; i++) {
        res[i] = mod_q(a[i] - b[i], q);
    }
}

// Vector scalar multiplication mod q
void vector_scalar_mul(int *res, const int *a, int scalar, int length, int q) {
    for (int i = 0; i < length; i++) {
        res[i] = mod_q(a[i] * scalar, q);
    }
}
