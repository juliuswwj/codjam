#!/usr/bin/python3

N = 10001
M = 1000000007

def getprimes():
    pp = [True] * N
    for i in range(2,N):
        if not pp[i]: continue
        j = 2
        while i*j < N:
            pp[i*j] = False
            j += 1
    ret=[]
    for i in range(2,N):
        if pp[i]: ret.append(i)
    return ret

def getfcnt():
    fcnt = []
    for i in range(N):
        fcnt.append([1])
    for t in range(1,N):
        i = 2
        while t*i < N:
            fcnt[t*i].extend([1+x for x in fcnt[t]])
            i += 1
    return fcnt
            
PRIMES = getprimes()
FCNT = getfcnt()

print(PRIMES)
print(len(FCNT))
