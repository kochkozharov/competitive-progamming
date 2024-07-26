for _ in range(int(input())):
    n, k = map(int, input().split())
    a=list(map(int, input().split()))
    a.sort()
    ans=0
    pr = [0] * (n + 1)
    for i in range(n):
        pr[i + 1] = pr[i] + a[i]
    for i in range(k + 1):
        ans = max(ans, pr[n - (k - i)] - pr[2 * i])
    print(ans)