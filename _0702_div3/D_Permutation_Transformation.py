def solve(N, A):
    def dfs(l, r, d):
        if l > r: return
        idx = l
        for i in xrange(l + 1, r + 1):
            if A[i] < A[idx]: continue
            idx = i
        ans[idx] = d
        dfs(l, idx - 1, d + 1)
        dfs(idx + 1, r, d + 1)
    ans = [0] * N
    dfs(0, N-1, 0)
    return ' '.join(map(str, ans))


for _ in xrange(int(raw_input())):
    N = int(raw_input())
    A = map(int, raw_input().split())
    print solve(N, A)
