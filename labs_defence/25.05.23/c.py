for _ in range(int(input())):
    s = input()
    rc = '0'
    ns =''
    for c in s:
        if c=='?':
            ns += rc
        elif c == '0':
            ns+='0'
            rc = '0'
        else:
            ns+='1'
            rc = '1'
    print(ns)
