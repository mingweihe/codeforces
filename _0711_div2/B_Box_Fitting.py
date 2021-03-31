from heapq import heappush, heappop
from collections import Counter
    
def solve():
    n, w = map(int, raw_input().split())
    a = map(int, raw_input().split())
    cnts = Counter(a)
    keys = sorted(cnts.keys(), reverse=True)
    ans = 0
    while n:
        x = w
        ans += 1
        for k in keys:
            while x - k >= 0 and cnts[k] > 0:
                cnts[k] -= 1
                x -= k
                n -= 1
    print ans

for _ in xrange(int(raw_input())):
    solve()
