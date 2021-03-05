def solve(n, A):
    A.sort()
    dp = [0] * (A[-1] + 1)
    for i in xrange(n):
        if i and A[i] == A[i-1]:
            dp[A[i]] += 1
            continue
        for div in xrange(1, int(A[i]**.5) + 1):
            if A[i] % div: continue
            dp[A[i]] = max(dp[A[i]], dp[div] + 1)
            if div != 1: dp[A[i]] = max(dp[A[i]], dp[A[i]/div] + 1)
    return n - max(dp)

for _ in xrange(int(raw_input())):
    n = int(raw_input())
    A = map(int, raw_input().split())
    print solve(n, A)
