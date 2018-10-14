t=input()
while t>0:
    sr=raw_input()
    s=raw_input()
    st=s.split()
    l=len(st)
    ans=int(st[0])
    i=1
    while i<l:
        if st[i]=='*':
            ans*=(int(st[i+1]))
        elif st[i]=='+':
            ans+=(int(st[i+1]))
        elif st[i]=='-':
            ans-=(int(st[i+1]))
        elif st[i]=='/':
            ans//=(int(st[i+1]))
        elif st[i]=='=':
            print(ans)
            break
        i+=1
    t-=1    