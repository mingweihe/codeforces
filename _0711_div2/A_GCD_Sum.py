def gcd(a, b):
    if b == 0: return a
    return gcd(b, a%b)


def solve():
    n = int(raw_input())
    while True:
        x, d = n, 0
        while x:
            x, rem = divmod(x, 10)
            d += rem
        if gcd(n, d) > 1:
            print n
            break
        n += 1


for _ in xrange(int(raw_input())):
    solve()
# print gcd(24, 16)
