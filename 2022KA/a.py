#!/usr/bin/python3

import sys


def run():
    I = sys.stdin.readline().strip()
    P = sys.stdin.readline().strip()
    if I == P: return '0'
    if len(P) <= len(I): return 'IMPOSSIBLE'

    i = 0
    p = 0
    ans = 0
    while i<len(I) and p<len(P):
        if I[i] == P[p]:
            i += 1
            p += 1
            continue
        p += 1
        ans += 1
    ans += len(P)-p
    return 'IMPOSSIBLE' if i<len(I) else str(ans)


T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
