def solve(N, A):
    to_use = 0
    for i, x in enumerate(A):
        if x + to_use < i: return 'NO'
        to_use += x-i
    return 'YES'


T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
