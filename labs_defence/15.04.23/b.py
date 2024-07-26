from math import ceil, floor
t=int(input())
for _ in range(t):
    s=input()
    if '0' not in s:
        print(len(s)*len(s))
        continue
    if '1' not in s:
        print(0)
        continue
    maxl=0
    l=0
    f=True
    save=0
    for i in range(len(s)):
        if s[i]=='1':
            l+=1
        else:
            if f:
                f=False
                save = l
            maxl=max(maxl, l)
            l=0
    save+=l
    maxl=max(save, maxl)
    print(ceil((maxl+1)/2)*floor((maxl+1)/2))