def solve(n, k):
    x = k / 2 + (k & 1)
    ans = []
    for i in xrange(x, n+1):
        if i == k: continue
        ans += i,
    return ans

for _ in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())
    ans = solve(n, k)
    print len(ans)
    print ' '.join(map(str, ans))
