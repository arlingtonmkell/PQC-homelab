#ifndef VERIFY_H
#define VERIFY_H

#include "keygen.h"
#include "sign.h"
#include <stddef.h>

int verify_signature(const PublicKey *pub, const int *message, size_t msg_len, const Signature *signature);

#endif // VERIFY_H
