t = int(input())
for _ in range(t):
    s=input()
    cnt=0
    if len(s)%2!=0:
        s=s[:len(s)//2]+s[len(s)//2+1:]
    for i in range(1,len(s)):
        if s[i]!=s[i-1]:
            print("YES")
            break
    else:
        print("NO")