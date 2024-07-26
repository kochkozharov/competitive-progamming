t = int(input())
for _ in range(t):
    s=input()
    if s=="^":
        print(1)
        continue
    r=0
    if (s[0]!="^"):
        s = "^"+s
        r+=1
    for i in range(2,len(s)):
        if s[i]=="_" and s[i-1]=="_":
            r+=1
    if (s[-1]!="^"):
        r+=1
    print(r)