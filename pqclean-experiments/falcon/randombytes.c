#include "randombytes.h"
#include <stdlib.h>
#include <stdint.h>

void randombytes(uint8_t *output, size_t output_len) {
    for (size_t i = 0; i < output_len; i++) {
        output[i] = rand() % 256;
    }
}
