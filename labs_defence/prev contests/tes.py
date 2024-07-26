t = int(input())
for i in range(t):
    a,b,c,d = map(int, input().split())
    if (d < b or (c-a > d-b)):
        print(-1)
    else:
        print(abs(b-d) + abs(c - (a+abs(b-d))))