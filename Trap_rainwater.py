def count(arr):
	water=0
	left=[0]*len(arr)
	right=[0]*len(arr)
	left[0]=arr[0]
	right[-1]=arr[-1]
	for i in range(1,len(arr)):
		if arr[i]>left[i-1]:
			left[i]=arr[i]
		else:
			left[i]=left[i-1]
	for i in range(len(arr)-2,-1,-1):
		right[i]=max(right[i+1],arr[i])
	for i in range(len(arr)):
		water+=(min(left[i],right[i])-arr[i])
	print(water)

l=list(map(int,input().split()))
count(l)
