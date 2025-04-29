from module_ops import mat_vec_mul
from utils import random_ring_matrix, random_small_vector
from ring import poly_add
from params import k

def keygen():
    A  = random_ring_matrix(k)
    s = random_small_vector(k)
    e = random_small_vector(k)

    As = mat_vec_mul(A, s)
    b = [poly_add(As[i], e[i]) for i in range(k)]

    print("Matrix A:", A)
    print("Secret s:", s)
    print("Error e:", e)
    print("Computed b:", b)
    print("Computed A·s:", mat_vec_mul(A, s))

    return (A, b), s # Public key (A, b), secret key = s
