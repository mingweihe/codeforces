def solve(n, m, s, t):
    left = [-1] * m
    right = [-1] * m
    j = 0
    for i, c in enumerate(s):
        if j == m: break
        if c == t[j]:
            left[j] = i
            j += 1
    j = m - 1
    for i in xrange(n-1, -1, -1):
        if j == -1: break
        if s[i] == t[j]:
            right[j] = i
            j -= 1
    ans = 0
    for i in xrange(1, m):
        ans = max(ans, right[i]-left[i-1])
    return ans

n, m = map(int, (raw_input().split()))
s = raw_input().strip()
t = raw_input().strip()
ans = solve(n, m, s, t)
print '{}'.format(ans)
