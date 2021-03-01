from collections import defaultdict


def solve(a, b, k, A, B):
    ans = 0
    Boys = defaultdict(set)
    Girls = defaultdict(set)
    for x, y in zip(A, B):
        Boys[x].add(y)
        Girls[y].add(x)
    for x, y in zip(A, B):
        Boys[x].discard(y)
        Girls[y].discard(x)
        k -= 1
        ans += k - (len(Boys[x]) + len(Girls[y]))
    return ans

T = int(raw_input())
for i in xrange(1, T+1):
    a, b, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    ans = solve(a, b, k, A, B)
    print '{}'.format(ans)
