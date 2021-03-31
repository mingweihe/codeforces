def solve():
    a = raw_input()
    b = raw_input()
    ans = float('-inf')
    for i in xrange(len(a)):
        for j in xrange(i, len(a)):
            if a[i:j+1] in b:
                ans = max(ans, j-i+1)
    print len(a) + len(b) if ans == float('-inf') else len(a) + len(b) - 2 * ans

for _ in xrange(int(raw_input())):
    solve()
