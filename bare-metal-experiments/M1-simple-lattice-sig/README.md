# M1: Simple Lattice-Based Signature Scheme

This project implements a basic digital signature system using lattice-style math over small integers in C.

It is part of the `PQC-homelab` and is designed for step-by-step understanding of key generation, signing, and verification using modular arithmetic and vector operations.

---

## How it Works

- **Private Key**: A short vector of small integers.
- **Public Key**: The same vector reduced modulo `q` (a small prime).
- **Message Hashing**: The message is reduced to a small integer using a simple hash function (sum of integers mod 5).
- **Signature**: Each private key element is multiplied by the hash and small noise is added. The result is reduced modulo `q`.
- **Verification**: The verifier computes the same hash, multiplies the public key by it, and compares the result to the signature. A signature is valid if the difference is within a small error margin.

---

## Parameters

- `q = 17`: All calculations are performed modulo 17.
- `LATTICE_DIM = 8`: Vectors are 8 elements long.
- `Noise`: Random integers from {-1, 0, 1}.

---

## File Structure
src/main.c

src/lattice.c

src/lattice.h

src/keygen.c

src/keygen.h

src/sign.c

src/sign.h

src/verify.c

src/verify.h

src/utils.c

src/utils.h

Makefile

README.md

---

## How to Build and Run

make clean
make
./lattice_sig

---

