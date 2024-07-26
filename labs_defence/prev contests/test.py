#from time import sleep
n = int(input())
for i in range(n):
	r, c = map(int, input().split())

	r0 = c0 =  0
	t = 0
	if r >= 0 and c <= 0:
		while ((c0 != c ) and (r0 != r)):
			r0+=1
			c0-=1
			t+=2
	if r >= 0 and c >= 0:
		while ((c0 != c ) and (r0 != r)):
			r0+=1
			c0+=1
			t+=2
	
	if r <= 0 and c >= 0:
		while ((c0 != c) and (r0 != r)):
			r0-=1
			c0+=1
			t+=2
		
	if r <= 0 and c <= 0:
		while ((c0 != c ) and (r0 != r)):
			r0-=1
			c0-=1
			t+=2
	
	if(c0 == c):
		if abs(r0-r) != 0:
			print(abs(r0 - r)*2+t -1)
		else:
			print(t)
	else:
		if abs(c0-c) != 0:
			print(abs(c0 - c)*2+t -1)
		else:
			print(t)
