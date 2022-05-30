#!/usr/bin/python3

def count(v):
    b = 10
    for i in range(1, 1000):
        if v < b: return i
        b *= 10
    return 1000

def solve():
    N = int(input())
    x = list(map(int, input().split(' ')))
    ans = 0
    for i in range(1, N):
        last = x[i-1]
        if x[i] > last:
            continue
        c1 = count(last)
        c2 = count(x[i])
        if c1 == c2:
            x[i] *= 10
            ans += 1
            continue
        m = 10**(c1-c2)
        v = last//m
        if v < x[i]:
            x[i] *= m
            ans += c1-c2
            continue
        if v == x[i] and (last%m+1) != m:
            x[i] = last+1
            ans += c1-c2
            continue
        x[i] *= m*10
        ans += c1-c2+1
    return ans

T = int(input())
for t in range(T):
    print(f'Case #{t+1}: {solve()}')
