#!/usr/bin/python3

import sys

cache = [None]*100001

def interesting(n):
    if cache[n] != None: return cache[n]

    p = 1
    s = 0
    while n > 0:
        p *= n%10
        s += n%10
        n = n // 10
    cache[n] = p%s == 0
    return cache[n]

def run():
    A,B = list(map(int, sys.stdin.readline().strip().split(' ')))
    ans = 0
    for i in range(A, B+1):
        if interesting(i): ans += 1
    return str(ans)

T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
