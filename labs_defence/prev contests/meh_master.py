from itertools import permutations
t = int(input())
for i in range(t):
    n = int(input())
    arr = list(map(int, input().split()))
    nulls = 0
    for i in arr:
        if i ==0:
            nulls+=1
    k = len(arr) - nulls
    if nulls <= k+1:
        print(0)
    elif max(arr) == 1:
        print(2)
    else:
        print(1)