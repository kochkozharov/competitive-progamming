for _ in range(int(input())):
    n = int(input())
    a=[]
    for i in range(1,n):
        a.append(i+1)
    print(n-sum(a)%n,*a)