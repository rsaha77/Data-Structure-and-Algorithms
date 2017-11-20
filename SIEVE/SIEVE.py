import math

MAXN = 501
isprime = [1] * MAXN
pfactsof = []


def sieve():
    isprime[0] = isprime[1] = 0
    for i in range(MAXN):
        foo = []
        pfactsof.append(foo)
    for i in range(2, int(math.sqrt(MAXN))):
        if isprime[i]:
            for j in range(i * i, MAXN, i):
                isprime[j] = 0
                pfactsof[j].append(i)


sieve()
cnt = 0
for num in range(0, 501):
    if isprime[num]:
        cnt += 1
        print (num)
print(cnt)
