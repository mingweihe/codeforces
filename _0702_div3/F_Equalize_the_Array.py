from collections import Counter
def solve(N, A):
    ans = float('inf')
    cnts = Counter(Counter(A).values())
    for x in cnts.keys():
        cur = 0
        for y in cnts.keys():
            if y > x: cur += (y - x) * cnts[y]
            elif y < x: cur += y * cnts[y]
        ans = min(ans, cur)
    return ans


for _ in xrange(int(raw_input())):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print ans

