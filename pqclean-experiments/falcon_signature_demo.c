#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "inner.h"
#include "api.h"
#define FALCON_PUBLICKEYBYTES 897
#define FALCON_SECRETKEYBYTES 1281
#define FALCON_SIGNATUREMAXBYTES 690

int crypto_sign_keypair(uint8_t *pk, uint8_t *sk);
int crypto_sign_signature(uint8_t *sig, size_t *siglen, const uint8_t *m, size_t mlen, const uint8_t *sk);
int crypto_sign_verify(const uint8_t *sig, size_t siglen, const uint8_t *m, size_t mlen, const uint8_t *pk);


int main() {
    uint8_t pk[FALCON_PUBLICKEYBYTES];
    uint8_t sk[FALCON_SECRETKEYBYTES];

    uint8_t message[] = "Hello PQC world!";
    uint8_t sig[FALCON_SIGNATUREMAXBYTES];
    size_t siglen;

    // Generate keypair
    if (crypto_sign_keypair(pk, sk) != 0) {
        printf("Keypair generation failed.\n");
        return 1;
    }

    // Sign the message
    if (crypto_sign_signature(sig, &siglen, message, sizeof(message), sk) != 0) {
        printf("Signing failed.\n");
        return 1;
    }

    printf("Signature created successfully. Signature length: %zu bytes\n", siglen);

    // Verify the signature
    if (crypto_sign_verify(sig, siglen, message, sizeof(message), pk) == 0) {
        printf("Signature verified successfully!\n");
    } else {
        printf("Signature verification failed.\n");
    }

    return 0;
}

// Keypair generation wrapper
int crypto_sign_keypair(uint8_t *pk, uint8_t *sk) {
    return PQCLEAN_FALCON512_CLEAN_crypto_sign_keypair(pk, sk);
}

// Signature generation wrapper
int crypto_sign_signature(uint8_t *sig, size_t *siglen,
                           const uint8_t *m, size_t mlen,
                           const uint8_t *sk) {
    return PQCLEAN_FALCON512_CLEAN_crypto_sign_signature(sig, siglen, m, mlen, sk);
}

// Signature verification wrapper
int crypto_sign_verify(const uint8_t *sig, size_t siglen,
                        const uint8_t *m, size_t mlen,
                        const uint8_t *pk) {
    return PQCLEAN_FALCON512_CLEAN_crypto_sign_verify(sig, siglen, m, mlen, pk);
}
