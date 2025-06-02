#!/usr/bin/env python3
from random import *
from sys import argv

def random_case(N, Q, L, R):
    print(N, Q)
    for i in range(N):
        print(randint(L, R), end=' ')
    print()
    for i in range(Q):
        mtd = randint(1, 2)
        if mtd == 1:
            l, r = randint(1, N), randint(1, N)
            l, r = min(l, r), max(l, r)
            print(1, l, r)
        else:
            pos = randint(1, N)
            print(2, pos)
if __name__ == "__main__":
    assert len(argv) == 5, "Usage: python3 random.py <N> <Q> <L> <R>"
    N = int(argv[1])
    Q = int(argv[2])
    L = int(argv[3])
    R = int(argv[4])
    if L > R:
        raise ValueError("L should be less than or equal to R.")
    if N <= 0 or Q <= 0:
        raise ValueError("N and Q should be positive integers.")
    random_case(N, Q, L, R)
