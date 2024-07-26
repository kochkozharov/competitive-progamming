t = int(input())
for i in range(t):
    n, k = list(map(int, input().split()))
    if (n % 2 == 0) or (n%2 != 0 and (n - k) % 2 == 0 and (n - k >= 0)):
        print("YES")
    else: print("NO")