from ring import poly_add, poly_mul
from params import k, q, n


def mat_vec_mul(A, s):
    result = []
    for i in range(k):
        acc = [0,0]
        for j in range(k):
            acc = poly_add(acc, poly_mul(A[i][j], s[j]))
        result.append(acc)
    return result
