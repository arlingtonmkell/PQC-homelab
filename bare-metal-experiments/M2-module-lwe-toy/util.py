import random
from params import q, n, k

def random_small_poly():
    return [random.choice([-1, 0, 1]) for _ in range(n)]

def random_ring_poly():
    return [random.randint(0, q - 1) for _ in range(n)]

def random_small_vector(k):
    return [random_small_poly() for _ in range(k)]

def random_ring_matrix(k):
    return [[random_ring_poly for _ in range(k)] for _ in range(k)];
