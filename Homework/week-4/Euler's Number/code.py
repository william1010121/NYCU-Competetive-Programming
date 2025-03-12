N=int(input())
ans=1
cur=1
for i in range(1,N+1) :
    cur /= i
    ans += cur
print(ans)
