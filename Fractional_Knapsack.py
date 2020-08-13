w=[5,10,20,30,40]
p=[30,20,100,90,160]
ratio=[]
d={}
for i in range(len(w)):
    ratio.append(int(p[i]/w[i]))
    d[int(p[i]/w[i])]=(w[i],p[i])
ratio=sorted(ratio,reverse=True)
W=60
profit=0
print(d)
print(ratio)
for i in range(len(ratio)):
    if W>=d[ratio[i]][0]:
        W-=d[ratio[i]][0]
        profit+=d[ratio[i]][1]
    else:
        profit+=(d[ratio[i]][1]*W)/d[ratio[i]][0]
        break
print(profit)
