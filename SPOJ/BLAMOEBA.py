# Solution reduces to this formulae
# x/y = (m**(n-1)+m**(n-2)....+m**(0)) / m**n
# x = (y-1) / (m-1)
# y = m**n
from sys import stdin
mod = 1000000007

def modexp(m,n):
    if n==0:
        return 1
    
    ans = 1
    
    if n%2==0:
        ans = modexp(m,n//2) % mod
        ans = ans**2 % mod
    else:
        ans = (modexp(m,n-1) % mod * m) % mod
    return ans

def inverse(n,m):
    # https://cp-algorithms.com/algebra/extended-euclid-algorithm.html
    if n==0:
        return (0,1,m)
    x1,y1,g = inverse(m%n,n)
    y = x1
    x = y1 - (m//n)*x1
    return (x,y,g)

def solve(m):
    x,y,g = inverse(m,mod)
    return x


for _ in range(int(stdin.readline())):
    m,n = list(map(int,stdin.readline().split()))
    y = modexp(m,n)%mod
    inv = solve(m-1)
    print(inv)
    print(((y-1)*inv))
    x = ((y-1)*inv)%mod
    print(x,y)


# 1
# 4 3
