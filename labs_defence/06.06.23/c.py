for _ in range(int(input())):
    n, k, q = map(int, input().split(' '))
    a = list(map(int, input().split(' ')))
    len = 0
    res = 0
    for d in a:
        if d <= q:
            len += 1
        else:
            if len >= k:
                res += (len - k + 1) * (len - k + 2) // 2
            len = 0
    if len >= k:
        res += (len - k + 1) * (len - k + 2) // 2
    print(res)