from module_ops import mat_vec_mul
from utils import random_small_vector, random_small_poly
from ring import poly_add, poly_mul
from params import k, q

def encrypt(pk, m):
    A, b = pk

    r = random_small_vector(k)
    e1 = random_small_vector(k)
    e2 = random_small_poly()

    u = [poly_add(x, e1[i]) for i, x in enumerate(mat_vec_mul(A, r))]

    b_dot_r = [0, 0]
    for i in range(k):
        b_dot_r = poly_add(b_dot_r, poly_mul(b[i], r[i]))

    encoded_m = [(q // 2) * bit for bit in m]
    b_dot_r = [0, 0]
    for i in range(k):
        b_dot_r = poly_add(b_dot_r, poly_mul(b[i], r[i]))

    v = poly_add(b_dot_r, poly_add(encoded_m, e2))

    print("Random r:", r)
    print("Error e1:", e1)
    print("Error e2:", e2)
    print("Computed u:", u)
    print("Computed v:", v)

    return u, v, r
