from math import gcd

for _ in range(int(input())):
    res = 0
    n = int(input())
    x = map(int , input().split())
    for i,val in enumerate(x):
        res = gcd(res, abs(val - i-1))
    print(res)