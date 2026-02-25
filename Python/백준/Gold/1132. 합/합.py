list = []
alp={chr(i+ord('A')):[] for i in range(10)}
weight=[0]*10
fir=[]
n=int(input())
for i in range(n):
    list.append(input())
    
for word in list:
    for j in range(len(word)):
        weight[ord(word[j])-ord('A')] += 10**(len(word)-j-1)
    fir.append(word[0])

for i in range(len(weight)):
    alp[chr(i+ord('A'))].append(weight[i])
    
alp=sorted(alp.items(), key=lambda x:x[1], reverse = True)

for i in range(9, -1, -1):
    if alp[i][0] not in fir:
        temp = alp[i]
        alp.remove(temp)
        alp.append(temp)
        break
        
res = 0
for i in range(10):
    res += int(alp[i][1][0])*(9-i)
print(res)


