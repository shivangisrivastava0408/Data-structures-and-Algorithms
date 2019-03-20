a=int(input())
b=int(input())
if a<b:
	a,b=b,a
def solve(c,d):
	if c%d==0:
		return d
	else:
		return solve(d,c%d)
x=solve(a,b)
print(x)

