for _ in range(int(input())):
    n = int(input())
    _a = list(map(int, input().split()))
    a = [_a[0]]
    for i in range(1, len(_a)):
        if _a[i-1] != _a[i]:
            a.append(_a[i])
    n = len(a)
    ans = n
    for i in range(0,n-2,1):
        if (a[i] < a[i+1] and a[i+1] < a[i+2]):
            ans -= 1
        if (a[i] > a[i + 1] and a[i + 1] > a[i + 2]):
            ans -= 1
    print(ans)