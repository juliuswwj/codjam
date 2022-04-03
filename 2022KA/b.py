#!/usr/bin/python3

import sys


def run():
    n = sys.stdin.readline().strip()
    c = 0
    for ch in n: c += int(ch)
    r = (9-c%9)%9
    if r == 0: return n[0] + '0' + n[1:]
    for i in range(len(n)):
        if int(n[i])>r: return n[:i] + str(r) + n[i:]
    return n + str(r)

T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
