MAXN = 500
prime = [1] * MAXN
facts = [0] * MAXN
pfacts = []
pfactsof = []

for i in range (0, MAXN):
    foo = []
    pfactsof.append(foo)
for i in range (2, MAXN):
    if prime[i] == 1:
        pfacts.append(i)
        for j in range (i*2, MAXN, i):
            prime [j] = 0
            facts [j] += 1
            pfactsof[j].append(i)


print (pfactsof[345])

'''
for num in range (1, MAXN):
    print(num, " ", facts [num])


for facts in pfacts:
    print (facts)
'''