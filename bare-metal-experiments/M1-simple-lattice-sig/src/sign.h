#ifndef SIGN_H
#define SIGN_H

#include "keygen.h"  // So we can use PrivateKey
#include <stddef.h>  // For size_t

// Signature structure
typedef struct {
    int sig[LATTICE_DIM];  // Signature vector
} Signature;

// Sign a message
void sign_message(const PrivateKey *priv, const int *message, size_t msg_len, Signature *signature);

#endif // SIGN_H
