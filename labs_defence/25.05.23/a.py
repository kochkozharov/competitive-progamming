for _ in range(int(input())):
    a,b = (list(map(int, input().split())))
    if (a % b != 0):
        print(1)
        print(a)
    else:
        print(2)
        print(a + 1, -1)