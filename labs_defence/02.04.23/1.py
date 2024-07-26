t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    xor = 0
    for x in a:
        xor ^=x
    if n%2 ==1:
        print(xor)
    else:
        if xor==0: print(7)
        else: print(-1)