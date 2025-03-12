from random import *
N=5
M=5
print(N,M)
for i in range(M) :
    mth = randint(1,3)
    if mth == 3 :
        print(3,randint(1,N))
    else :
        print(mth,randint(1,N),randint(1,N))
