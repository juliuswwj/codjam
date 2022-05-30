#!/usr/bin/python3

import math

C = [[1], [1, 1]]

for i in range(2, 100):
    c = [1]
    C.append(c)
    for j in range(1, i):
        c.append(C[i-1][j-1]+C[i-1][j])
    c.append(1)

def inv(s):
    ans = ''
    for c in s:
        ans += 'T' if c == 'F' else 'F'
    return ans

def solve():
    N,Q = list(map(int, input().split(' ')))
    Z = []
    S = []
    for n in range(N):
        z,s = input().split(' ')
        Z.append(z)
        S.append(int(s))

    if N == 1:
        return (S[0], 1, Z[0]) if S[0]*2>Q else (Q-S[0], 1, inv(Z[0]))

    
    A = 0
    B = 0
    for i in range(Q):
        if Z[0][i] == Z[1][i]:
            A += 1
        else:
            B += 1

    a = S[0]+S[1]-B
    if a<0 or a>Q or a%2: raise f"error input"
    a //= 2
    b = S[0] - a
    
    ans = ''
    for i in range(Q):
        if Z[0][i] == Z[1][i]:
            ans += Z[0][i] if a*2>A else inv(Z[0][i])
        else:
            ans += Z[0][i] if b*2>B else inv(Z[0][i])

    a = a if a*2>A else (A-a)
    b = b if b*2>B else (B-b)
    return (a + b, 1, ans)
    

T=int(input())
for t in range(T):
    X,Y,Z = solve()
    print(f'Case #{t+1}: {Z} {X}/{Y}')
    
