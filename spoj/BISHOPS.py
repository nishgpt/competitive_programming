i=0
while i < 1024: 
    num=raw_input()
    n = int(num)
    if n < 2:
        ans = 1
    else:
        ans = 2*n-2
    print(ans)
    i+=1        