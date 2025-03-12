N=int(input())

for _ in range(N) :
    fst = list(map(int,input().split()))
    sec = list(map(int,input().split()))
    d = fst[-1]
    fst.pop()
    c = fst[-1]
    fst.pop()

    dic = {}

    def f(x,y) :
        if x<= 0 or y<=0 :
            return d
        if (x,y) in dic : 
            return dic[(x,y)]
        ans = 0
        for a,b in zip(fst[0::2],fst[1::2]):
            ans += f(x-a,y-b)
        ans += c
        dic[(x,y)] = ans
        return ans
    for x,y in zip(sec[0::2],sec[1::2]):
        print(f(x,y))
    print()
