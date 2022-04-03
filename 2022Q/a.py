#!/usr/bin/python3

import sys

def run():
    R,C = tuple(map(int, sys.stdin.readline().strip().split(' ')))

    br = '+-'*C + '+'
    ret = ['..'+br[2:], ]
    for r in range(R):
        ret.append(('.' if r == 0 else '|') + '.|'*C)
        ret.append(br)
    return '\n'.join(ret)


T=int(sys.stdin.readline())
for t in range(T):
    print("Case #%d:\n%s" %(t+1, run()))
