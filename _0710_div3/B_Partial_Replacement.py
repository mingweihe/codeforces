def solve():
    _, k = map(int, raw_input().split())
    s = raw_input()
    l, r = -1, -1
    for i, x in enumerate(s):
        if x == '*':
            r = i
            if l == -1: l = i
    if l == r:
        print 1
        return
    last_x = l
    last_star = l
    ans = 2
    for i in xrange(l+1, r+1):
        if i - last_x > k:
            ans += 1
            last_x = last_star
        if s[i] == '*':
            last_star = i
    print ans

for _ in xrange(int(raw_input())):
    solve()
