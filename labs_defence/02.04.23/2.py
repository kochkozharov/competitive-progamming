t = int(input())
for _ in range(t):
    n  = int(input())
    s = input()
    for i in range(ord('a'), ord(s[0])+1):
        if chr(i) in s:
            q = s.rfind(chr(i))
            print(chr(i)+s[:q]+s[q+1:])
            break