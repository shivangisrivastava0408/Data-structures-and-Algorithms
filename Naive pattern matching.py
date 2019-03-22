s=input()
p=input()
m,n=len(s),len(p)
f=0
for w in range(m):
	if s[w]==p[0]:
		if s[w:w+n]==p:
			f=1
			print("Pattern found")
			break
if f==0:
	print("Pattern not found")
