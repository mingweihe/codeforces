from sys import stdout


def query(l, r):
    print '? {} {}'.format(l, r)
    stdout.flush()
    ans = int(raw_input())
    return ans


def output_result(index):
    print '! {}'.format(index)


def helper(l, r, pos):
    if r - l == 1:
        if pos == l: return r
        else: return l
    mid = (l + r) / 2
    il = query(l, mid)
    ir = query(mid, r)
    if pos <= mid:
        if pos == il: return helper(l, mid, il)
        else: return helper(mid, r, ir)
    else:
        if pos == ir: return helper(mid, r, ir)
        else: return helper(l, mid, il)

def solve(n):
    ## Approach 2, two pointer iteration
    l, r = 1, n
    pos = query(l, r)
    while l + 1 < r:
        mid = (l + r) / 2
        il, ir = query(l, mid), query(mid, r)
        if pos >= mid:
            if ir == pos: l = mid
            else:
                r = mid
                pos = il
        else:
            if il == pos: r = mid
            else:
                l = mid
                pos = ir
    return l if pos == r else r

    ## Approach 1, recursion
    # l, r = 1, n
    # return helper(l, r, ask(l, r))

n = int(raw_input())
ans = solve(n)
output_result(ans)
