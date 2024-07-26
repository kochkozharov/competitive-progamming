for _ in range(int(input())):
    n=int(input())
    s=input()
    bal = [0]*(n+1)
    for j in range(n):
        if (s[j]=='('):
            bal[j+1]=bal[j]+1
        else:
            bal[j+1]=bal[j]-1
    if (bal[-1]!=0):
        print(-1)
    else:
        if (min(bal)==0 or max(bal)==0):
            print(1)
            print()
            for j in range(n):
                if (j): print(" ")
                print(1)
            print()
        else:
            print(2)
            ans=[]
            cur=0
            while (cur<n):
                w = 1 if (s[cur] == '(') else 2
                cur+=1
                ans.append(w)
                while(bal[cur] != 0):
                    cur+=1
                    ans.append(w)
            for j in range(n):
                if j: print(" ")
                print(ans[j])
            print()