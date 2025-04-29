from params import q, n

def poly_add(a, b):
    return [(a[i] + b[i]) % q for i in range(n)]

def poly_sub(a, b):
    return [(a[i] - b[i]) % q for i in range(n)]

def poly_mul(a, b): 
    r0 = (a[0] * b[0] - a[1] * b[1]) % q
    r1 = (a[0] * b[1] + a[1] * b[0]) % q
    return [r0, r1]
