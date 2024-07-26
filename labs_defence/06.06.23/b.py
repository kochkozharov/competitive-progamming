from math import log2
for _ in range(int(input())):
    n, k = map(int, input().split())
    if log2(n+1) <= k:
        print(n+1)
    else:
        print(1<<k)