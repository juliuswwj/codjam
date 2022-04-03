#!/usr/bin/python3

import sys

def read():
    return list(map(int, sys.stdin.readline().strip().split(' ')))

def run():
    n = read()[0]
    c = 0
    for s in sorted(read()):
        if s < c+1: continue
        c += 1
    return c

T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d: %s" %(t+1, run()))
