for _ in range(int(input())):
    n = int(input())
    s = input()
    l = ''
    for c in s:
        if l == c:
            print(str(l), end='')
            l = ''
        elif l == '':
            l = c
    print()
