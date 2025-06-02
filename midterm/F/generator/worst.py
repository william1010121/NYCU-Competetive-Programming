from random import randint
from sys import argv

def worst_case_all_0_1(N,Q):
    print(N,Q)
    for i in range(N):
        print(randint(0,1), end=' ')
    print()
    for i in range(Q):
        mtd = randint(1,2)
        if mtd == 1 :
            l,r = randint(1,N), randint(1,N)
            l,r = min(l,r), max(l,r)
            print(1,l,r)
        else:
            pos = randint(1,N)
            print(2,pos)
def worst_case_all_rnage(N,Q):
    print(N,Q)
    for i in range(N):
        print(randint(0,10**9), end=' ')
    print()
    for i in range(Q):
        mtd = randint(1,2)
        if mtd == 1 :
            # l nearly 1, r nearly N
            l = randint(1,N//10)
            r = randint(N//10*9,N)
            l,r = min(l,r), max(l,r)
            print(1,l,r)
        else:
            pos = randint(1,N)
            print(2,pos)

def worst_case_all_0(N,Q):
    print(N,Q)
    for i in range(N):
        print(0, end=' ')
    print()
    for i in range(Q):
        mtd = randint(1,2)
        if mtd == 1 :
            l,r = randint(1,N), randint(1,N)
            l,r = min(l,r), max(l,r)
            print(1,l,r)
        else:
            pos = randint(1,N)
            print(2,pos)

def worst_case_all_1(N,Q):
    print(N,Q)
    for i in range(N):
        print(1, end=' ')
    print()
    for i in range(Q):
        mtd = randint(1,2)
        if mtd == 1 :
            l,r = randint(1,N), randint(1,N)
            l,r = min(l,r), max(l,r)
            print(1,l,r)
        else:
            pos = randint(1,N)
            print(2,pos)


def worst_case_all_2(N,Q):
    print(N,Q)
    for i in range(N):
        print(2, end=' ')
    print()
    for i in range(Q):
        mtd = randint(1,2)
        if mtd == 1 :
            l,r = randint(1,N), randint(1,N)
            l,r = min(l,r), max(l,r)
            print(1,l,r)
        else:
            pos = randint(1,N)
            print(2,pos)

if __name__ == "__main__":
    # Check if the correct number of arguments is provided
    # Usage: python3 worst.py <N> <type>
    # N: Number of elements
    # type: Type of data structure (1 for list, 2 for deque)
    assert len(argv) == 3, "Usage: python3 worst.py<N> <type>"
    N = int(argv[1])
    Q = N
    if argv[2] == '1':
        # Worst case for list
        worst_case_all_0_1(N,Q)
    elif argv[2] == '2':
        # Worst case for deque
        worst_case_all_rnage(N,Q)
    elif argv[2] == '3':
        # Worst case for all 0
        worst_case_all_0(N,Q)
    elif argv[2] == '4':
        # Worst case for all 1
        worst_case_all_1(N,Q)
    elif argv[2] == '5':
        # Worst case for all 2
        worst_case_all_2(N,Q)
    else:
        raise ValueError("Invalid type. Use 1 for list, 2 for deque, 3 for all 0, 4 for all 1, 5 for all 2.")
