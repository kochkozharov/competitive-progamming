from math import ceil
t = int(input())
for i in range(t):
    a, b = map(int, input().split())
    ans = 1000000
    for k in range(1, 100000):
        ans = min(ans,ceil(a/k)+ceil(b/k)+k-1)
    print(ans)