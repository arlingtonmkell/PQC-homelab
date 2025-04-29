#include <stdio.h>
#include "keygen.h"
#include "sign.h"
#include "verify.h"

int main() {
    printf("M1 Lattice Signature Forge: Keygen + Signing Test\n");

    // 1. Keygen
    PrivateKey priv;
    PublicKey pub;
    generate_keypair(&priv, &pub);

    // 2. Print keys
    printf("Private Key: [ ");
    for (int i = 0; i < LATTICE_DIM; i++) printf("%d ", priv.sk[i]);
    printf("]\n");

    printf("Public Key: [ ");
    for (int i = 0; i < LATTICE_DIM; i++) printf("%d ", pub.pk[i]);
    printf("]\n");

    // 3. Simulated message (array of 4 ints)
    int message[4] = {1, 2, 3, 4};
    printf("Message: [ ");
    for (int i = 0; i < 4; i++) printf("%d ", message[i]);
    printf("]\n");

    // 4. Sign
    Signature sig;
    sign_message(&priv, message, 4, &sig);

    // 5. Print signature
    printf("Signature: [ ");
    for (int i = 0; i < LATTICE_DIM; i++) printf("%d ", sig.sig[i]);
    printf("]\n");

    // 6. Verify
    int valid = verify_signature(&pub, message, 4, &sig);

    if (valid) {
        printf("✅ Signature verified.\n");
    } else {
        printf("❌ Signature invalid.\n");
    }

    return 0;
}
