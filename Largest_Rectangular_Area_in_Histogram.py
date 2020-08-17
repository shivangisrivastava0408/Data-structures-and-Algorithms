def fun(l):
    n=len(l)
    lhs,rhs=[0]*n,[0]*n
    stack=[]
    for i in range(n):
        while stack!=[] and l[i]<l[stack[-1]]:
            stack.pop()
        if stack==[]:
            lhs[i]=i+1
        else:
            lhs[i]=i-stack[-1]
        stack.append(i)
    stack=[]
    for j in range(n-1,-1,-1):
        while stack!=[] and l[j]<=l[stack[-1]]:
            stack.pop()
        if stack==[]:
            rhs[j]=n-j
        else:
            rhs[j]=stack[-1]-j
        stack.append(j)
    max_area=-1
    for i in range(n):
        p=l[i]*(lhs[i]+rhs[i]-1)
        if p>max_area:
            max_area=p
    return max_area
    
l=[6, 2, 5, 4, 5, 1, 6]
print(fun(l))
