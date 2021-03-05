def solve(N, A):
    AA = sorted(enumerate(A), key=lambda x: x[1])
    presum = [0]
    for i in xrange(N):
        presum += presum[-1] + AA[i][1],
    AA += [0, 0],
    ans = []
    for i in xrange(N-1, -1, -1):
        if presum[i+1] < AA[i+1][1]: break
        ans += AA[i][0] + 1,
    return sorted(ans)


for _ in xrange(int(raw_input())):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print len(ans)
    print ' '.join(map(str, ans))
