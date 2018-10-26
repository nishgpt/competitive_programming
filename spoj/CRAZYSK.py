t=int(raw_input())
while t>0:
    s=raw_input()
    k=s.index(' ')
    n=int(s[:k])
    c=int(s[k+1:])
    i=n
    while n>=c:
        q=n/c
        r=n%c
        i=i+q
        n=q+r
    print(i)    
    t-=1