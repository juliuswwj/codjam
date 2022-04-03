#!/usr/bin/python3

import sys

def read():
    return tuple(map(int, sys.stdin.readline().strip().split(' ')))

def run():
    A = read()
    B = read()
    C = read()

    c = 1000000
    ans = []
    for i in range(4):
        t = min(A[i], B[i], C[i])
        v = min(t, c)
        c -= v
        ans.append(str(v))

    if c > 0: return 'IMPOSSIBLE'
    return ' '.join(ans)


T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
