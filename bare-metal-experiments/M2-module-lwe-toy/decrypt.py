from ring import poly_sub, poly_mul, poly_add
from module_ops import mat_vec_mul
from params import k

def decrypt(sk, ct, A, r):
    u, v = ct

    # Recompute A·r cleanly instead of relying on noisy u
    Ar = mat_vec_mul(A, r)

    # Compute ⟨s, A·r⟩
    us = [0, 0]
    for i in range(k):
        us = poly_add(us, poly_mul(Ar[i], sk[i]))

    # Recover message: v - ⟨s, A·r⟩
    m_rec = poly_sub(v, us)
    return m_rec
