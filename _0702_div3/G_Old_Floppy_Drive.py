from bisect import bisect_left


def solve(N, M, A, X):
    ans = [-1] * M
    inc = []
    maxi, total = float('-inf'), 0

    for i, x in enumerate(A):
        total += x
        if total <= maxi: continue
        maxi = total
        inc += [total, i],

    for i, x in enumerate(X):
        idx = bisect_left(inc, [x])
        if idx < len(inc):
            ans[i] = inc[idx][1]
            continue
        if total <= 0: continue

        extra = x - maxi
        num_circle = extra / total
        x -= num_circle * total
        idx = bisect_left(inc, [x])
        if idx == len(inc):
            num_circle += 1
            x -= total
            idx = bisect_left(inc, [x])
        ans[i] = num_circle * N + inc[idx][1]
    return ' '.join(map(str, ans))

for _ in xrange(int(raw_input())):
    N, M = map(int, raw_input().split())
    A = map(int, raw_input().split())
    X = map(int, raw_input().split())
    print solve(N, M, A, X)
