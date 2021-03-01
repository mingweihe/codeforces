def solve(A):
    p = A[0]
    ans = float('inf')
    for x in A[1:]:
        remain = p % x
        half = x / 2.0
        if remain == 0: return 0
        elif remain == half: ans = min(ans, half)
        else: ans = min(ans, x - remain)
    return int(ans)


T = int(raw_input())
for i in xrange(1, T+1):
    A = map(int, raw_input().split())
    ans = solve(A)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
