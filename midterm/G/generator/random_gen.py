#!/usr/bin/env python3
from random import *
from sys import argv

def random_case(N, K, L, R):
    print(N, K)
    for i in range(N):
        print(randint(L, R), end=' ')
    print()
if __name__ == "__main__":
    assert len(argv) == 6, "Usage: python3 random.py <N> <KL> <KR> <L> <R>"
    N = int(argv[1])
    K = randint(int(argv[2]), int(argv[3]))
    L = int(argv[4])
    R = int(argv[5])
    if L > R:
        raise ValueError("L should be less than or equal to R.")
    if N <= 0 or K < 0:
        raise ValueError("N and K should be positive integers.")
    random_case(N, K, L, R)
