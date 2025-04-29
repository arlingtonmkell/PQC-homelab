#include "keygen.h"
#include "lattice.h"
#include <stdlib.h>  // for rand()
#include <time.h>    // for seeding randomness

// Helper: Generate small random integer {-1, 0, 1}
int small_random() {
    int r = rand() % 3;  // 0, 1, or 2
    return r - 1;        // -1, 0, or 1
}

// Generate private and public key
void generate_keypair(PrivateKey *priv, PublicKey *pub) {
    // Seed random number generator (only once)
    static int seeded = 0;
    if (!seeded) {
        srand(time(NULL));
        seeded = 1;
    }

    // Generate private key: small random coefficients
    for (int i = 0; i < LATTICE_DIM; i++) {
        priv->sk[i] = small_random();
    }

    // Identity mapping (pub = sk)
    for (int i = 0; i < LATTICE_DIM; i++) {
        pub->pk[i] = mod_q(priv->sk[i], MODULUS_Q);
    }
}
