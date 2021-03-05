from sys import stdout


def query(l, r):
    print '? {} {}'.format(l, r)
    stdout.flush()
    ans = int(raw_input())
    return ans


def solve(n):
    pos = query(1, n)
    if pos != 1: x = query(1, pos)
    else: x = n
    ans = -1
    if x == pos:
        l, r = 1, pos - 1
        while l <= r:
            mid = l + r >> 1
            if query(mid, pos) == pos:
                ans = mid
                l = mid + 1
            else: r = mid - 1
    else:
        l, r = pos + 1, n
        while l <= r:
            mid = l + r >> 1
            if query(pos, mid) == pos:
                ans = mid
                r = mid - 1
            else:
                l = mid + 1
    return ans


n = int(raw_input())
ans = solve(n)
print '! {}'.format(ans)
