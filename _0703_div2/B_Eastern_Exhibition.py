def solve(N, A):
    if N & 1: return 1
    xs, ys = map(sorted, zip(*A))
    xs.sort()
    ys.sort()
    x1, x2 = xs[N/2-1], xs[N/2]
    y1, y2 = ys[N/2-1], ys[N/2]
    return (x2 - x1 + 1) * (y2 - y1 + 1)

T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    A = []
    for _ in xrange(N):
        A += map(int, raw_input().split()),
    ans = solve(N, A)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
