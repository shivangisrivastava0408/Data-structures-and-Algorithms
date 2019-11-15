def count(arr):
	a=max(arr)
	frequency=[0]*(a+1)
	output=[0]*len(arr)
	for x in arr:
		frequency[x]+=1
	j=0
	for w in range(a+1):
		if frequency[w]==0:
			continue
		else:
			for i in range(frequency[w]):
				output[j]=w
				j+=1
	return output

test=list(map(int,input().split()))
result=count(test)
print(result)
