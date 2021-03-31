def solve():
    n, m, x = map(int, raw_input().split())
    j, i = divmod(x-1, n)
    print i*m+j+1


for _ in xrange(int(raw_input())):
    solve()
