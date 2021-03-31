from heapq import heappush, heappop
from collections import Counter

def solve():
    n = int(raw_input())
    a = map(int, raw_input().split())
    hq = []
    cnts = Counter(a)
    for k, v in cnts.items():
        heappush(hq, [-v, k])
    ans = n
    while len(hq) > 1:
        cnt, x = heappop(hq)
        cnt2, y = heappop(hq)
        cnt, cnt2 = cnt + 1, cnt2 + 1
        if cnt != 0:
            heappush(hq, [cnt, x])
        if cnt2 != 0:
            heappush(hq, [cnt2, y])
        ans -= 2
    print ans

for _ in xrange(int(raw_input())):
    solve()
