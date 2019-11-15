def count(arr):
	a=max(arr)
	frequency=[0]*(a+1)
	output=[0]*len(arr)
	for x in arr:
		frequency[x]+=1
	for w in range(a+1):
		if w==0:
			continue
		else:
			frequency[w]=frequency[w]+frequency[w-1]
	for w in range(len(arr)):
		k=frequency[arr[w]]
		output[k-1]=arr[w]
		frequency[arr[w]]-=1
	return output

test=list(map(int,input().split()))
result=count(test)
print(result)
