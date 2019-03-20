import math
n=int(input())
prime=[]
for w in range(2,n+1):
	prime.append(w)
for w in range(2,int(math.sqrt(n))):
	if w in prime:
		for i in range(w*2,n+1,w):
			if i in prime:
				prime.remove(i)
print(prime)
