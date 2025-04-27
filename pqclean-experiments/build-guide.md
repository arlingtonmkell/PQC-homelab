# Build Guide: Falcon Signature Demo

This guide shows how to build and run the Falcon-512 signature demo (`falcon_signature_demo.c`) using the PQClean reference implementation.

## Prerequisites

- GCC compiler
- Basic C environment

Make sure you have the `falcon-512_clean.h` and related source files available. (Typically part of the PQClean structure.)

## Compile the Falcon Signature Demo

From inside the `pqclean-experiments/` directory:

```bash
gcc falcon_signature_demo.c -I../liboqs/src/oqs -o falcon_signature_demo
