from collections import Counter
t = int(input())


# 1111 -1
# 1222 6
# 1123 4
# 1122 4
# 1234 4

for i in range(t):
    c = sorted(list(Counter(input()).values()))
    if c == [1,3]:
        print(6)
    elif c==[4]:
        print(-1)
    else:
        print(4)