t=input()
p=input()
t1=''
p1=''
for w in t:
    t1+=str(ord(w)-96)
for w in p:
    p1+=str(ord(w)-96)
print(t1,p1)
q=13
t0=t1[:len(p)]
i=0
t0=int(t0)
p1=int(p1)
t1=int(t1)
while (i+len(p))<=len(str(t1)):
    print(t0,p1)
    if t0%q==p1%q:
        if t0==p1:
            print("Valid Hit")
            print("Pattern occurs at index",i)
        else:
            print("Spurious Hit")
    else:
        print("Invalid Hit")
    if (i+len(p))>=len(str(t1)):
        break
    t0=(t0-int(str(t0)[0])*(10**(len(p)-1)))*10+int(str(t1)[i+len(str(p1))])
    i+=1
    
