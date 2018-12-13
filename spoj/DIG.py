t=int(raw_input())
while t>0:
    n=int(raw_input())
    k=n*(n-1)*(n-2)*(n-3)
    k=k/24
    if k>1000000007:
        k=k%1000000007
    print(k)
    t-=1