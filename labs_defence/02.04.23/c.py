import bisect
t = int(input())
for _ in range(t):
    n, m = map(int, input().split())
    parabols=[]
    ks = []
    for _ in range(n):
        ks.append(int(input()))
    ks.sort()
    for _ in range(m):
        a, b, c = map(int, input().split())
        two_k=(ks[min(bisect.bisect_left(ks, b)-1, len(ks)-1)], ks[min(bisect.bisect_left(ks,b),len(ks)-1)])
        for k in two_k:
            if (b-k)**2 < 4*a*c:
                print("YES")
                print(k)
                break
        else:
            print("NO")
# k >= b-sqrt(4ac) and k <= b+sqrt(4ac)