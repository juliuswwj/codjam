#!/usr/bin/python3

import sys


def run():
    n = int(sys.stdin.readline().strip())
    s = sys.stdin.readline().strip()
    if n<5: return 'POSSIBLE'
    
    idx = []
    for i in range(n):
        if s[i] == '?':
            idx.append(i)

    for i in range(1<<len(idx)):
        ns = list(s)
        for j in range(len(idx)):
            ns[idx[j]] = str((i>>j)&1)
        print(i, ns)
        ok = True
        for j in range(2, n-2):
            if ns[j-2] == ns[j+2] and ns[j-1] == ns[j+1]: ok = False
        if ok: return 'POSSIBLE'

    return 'IMPOSSIBLE'


T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
