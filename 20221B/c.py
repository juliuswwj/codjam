#!/usr/bin/python3

import sys, random

def code(n):
    if n == 8: return '11111111'
    a = ['0']*(8-n) + ['1']*n
    random.shuffle(a)
    return ''.join(a)

def solve():
    print(code(4))
    nn = 4
    mad = False
    while True:
        n = int(input())
        if n == -1: sys.exit(1)
        if n == 0: break
        if n > nn*2:
            #sys.stderr.write("####mad\n")
            mad = True
        nn = n
        print(code(random.randint(1,8) if mad else n))


T = int(input())
for t in range(T):
    solve()