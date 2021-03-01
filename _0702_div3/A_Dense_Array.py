def helper(a, b):
    ans = 0
    while a < b:
        a <<= 1
        ans += 1
    return ans - 1


def solve(N, A):
    ans = 0
    for i in xrange(1, len(A)):
        if float(max(A[i], A[i-1])) / min(A[i], A[i-1]) <= 2: continue
        ans += helper(min(A[i], A[i-1]), max(A[i], A[i-1]))
    return ans


T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print '{}'.format(ans)
