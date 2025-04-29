#include "verify.h"
#include "lattice.h"
#include "utils.h"  // For simulate_hash
#include <stdlib.h> // abs()

int verify_signature(const PublicKey *pub, const int *message, size_t msg_len, const Signature *signature) {
    int hash = simulate_hash(message, msg_len);
    int error_bound = 3; // Max allowed error per component

    for (int i = 0; i < LATTICE_DIM; i++) {
        int expected = mod_q(pub->pk[i] * hash, MODULUS_Q);
        int actual = signature->sig[i];

        int diff = expected - actual;
        diff = (diff + MODULUS_Q) % MODULUS_Q;

        if (diff > MODULUS_Q / 2) {
            diff = MODULUS_Q - diff;  // Minimal absolute distance in mod space
        }

        if (diff > error_bound) {
            return 0;  // Signature invalid
        }
    }

    return 1;  // Signature valid
}
