#ifndef LATTICE_H
#define LATTICE_H

// Perform modular reduction: ensures result is in [0, q-1]
int mod_q(int a, int q);

// Add two vectors (element-wise), mod q
void vector_add(int *res, const int *a, const int *b, int length, int q);

// Subtract two vectors (element-wise), mod q
void vector_sub(int *res, const int *a, const int *b, int length, int q);

// Multiply vector by a scalar, mod q
void vector_scalar_mul(int *res, const int *a, int scalar, int length, int q);

#endif // LATTICE_H
