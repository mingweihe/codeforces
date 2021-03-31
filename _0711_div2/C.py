import sys
sys.setrecursionlimit(1000000)
# maximum recursion depth exceeded error (python)
def dfs(i, k, cache, n):
    if i == 0 or k == 1: return 1
    if (i, k) in cache: return cache[(i, k)]
    ans = dfs(i-1, k, cache, n) + dfs(n-i, k-1, cache, n)
    cache[(i, k)] = ans
    return ans
 
def solve():
    n, k = map(int, raw_input().split())
    print dfs(n, k, {}, n) % (10**9+7)
 
for _ in xrange(int(raw_input())):
    solve()
