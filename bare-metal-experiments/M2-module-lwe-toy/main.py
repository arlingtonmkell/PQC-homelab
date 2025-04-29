# main.py
from keygen import keygen
from encrypt import encrypt
from decrypt import decrypt
from params import q

def decode(poly):
    return [1 if x > q // 4 else 0 for x in poly]

def scale_message(m):
    """
    Encode binary message [0, 1] as [0, q//2]
    """
    return [(q // 2) * bit for bit in m]

def main():
    print("M2 Module-LWE Demo")

    # Key generation
    (A, b), sk = keygen()

    # Binary message
    m_binary = [1, 0]
    m = scale_message(m_binary)  # Proper LWE encoding
    print("Original message (binary):", m_binary)

    # Encrypt
    u, v, r = encrypt((A, b), m)
    ct = (u, v)
    print("Ciphertext (u, v):", ct)

    # Decrypt
    m_rec = decrypt(sk, ct, A, r)
    print("Decrypted message (raw):", m_rec)

    # Decode both
    original_decoded = m_binary
    recovered_decoded = decode(m_rec)
    print("Recovered (decoded):", recovered_decoded)

    if original_decoded == recovered_decoded:
        print("✅ Decryption successful.")
    else:
        print("❌ Decryption failed.")

if __name__ == "__main__":
    main()
