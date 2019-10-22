t=input()
p=input()
for w in range(len(t)-len(p)+1):
    f=0
    for a in range(len(p)):
        if t[w+a]==p[a]:
            continue
        else:
            f=1
            break
    if f==0:
        print("Pattern at index",w)
