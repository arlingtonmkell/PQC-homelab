#ifndef KEYGEN_H
#define KEYGEN_H

#define LATTICE_DIM 8  // Dimension of the lattice
#define MODULUS_Q  17  // Small modulus to keep values simple

// Key structures
typedef struct {
    int sk[LATTICE_DIM];  // Private key: small random vector
} PrivateKey;

typedef struct {
    int pk[LATTICE_DIM];  // Public key: derived vector
} PublicKey;

// Generate a keypair: fills private and public keys
void generate_keypair(PrivateKey *priv, PublicKey *pub);

#endif // KEYGEN_H
