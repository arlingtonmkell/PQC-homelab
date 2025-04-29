#include "sign.h"
#include "lattice.h"
#include <stdlib.h>  // rand()
#include "utils.h"


// Sign the message
void sign_message(const PrivateKey *priv, const int *message, size_t msg_len, Signature *signature) {
    int msg_hash = simulate_hash(message, msg_len);

    // Multiply private key by message hash
    for (int i = 0; i < LATTICE_DIM; i++) {
        int noisy = priv->sk[i] * msg_hash;

        // Add small random noise {-1, 0, 1}
        noisy += (rand() % 3) - 1;

        // Reduce mod q
        signature->sig[i] = mod_q(noisy, MODULUS_Q);
    }
}
