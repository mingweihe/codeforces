def solve(N, A):
    S = sorted(enumerate(A), key=lambda x: x[1])
    AA = []
    for i in xrange(N-1, -1, -1):
        origin_i, _ = S[i]
        AA += A[origin_i:]
        while len(A) > origin_i: A.pop()
        if not A: break
    return ' '.join(map(str, AA))


T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
