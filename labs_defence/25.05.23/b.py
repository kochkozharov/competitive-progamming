for _ in range(int(input())):
    _ = input()
    s = input()
    cb = 0
    cm = 0
    mcb=0
    mcm=0
    for c in s:
        if c=='>':
            cb+=1
            mcm=max(cm,mcm)
            cm=0
        else:
            cm+=1
            mcb=max(cb,mcb)
            cb=0
    mcb = max(mcb,cb)
    mcm = max(mcm,cm)
    print(max(mcb+1,mcm+1))