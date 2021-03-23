def helper(idx, ans, n, A):
    if idx == 4:
        for i in xrange(4):
            if ans[i] > A[i]: return False
        return True

    left_i = (idx - 1) % 4
    right_i = (idx + 1) % 4
    if A[idx] == n:
        ans[left_i] += 1
        ans[right_i] += 1
        if helper(idx + 1, ans, n, A): return True
        ans[left_i] -= 1
        ans[right_i] -= 1
    elif A[idx] == n - 1:
        ans[left_i] += 1
        if helper(idx + 1, ans, n, A): return True
        ans[left_i] -= 1
        ans[right_i] += 1
        if helper(idx + 1, ans, n, A): return True
        ans[right_i] -= 1
    else:
        if helper(idx + 1, ans, n, A): return True
    return False

def solve(n, U, R, D, L):
    ans = [0, 0, 0, 0]
    A = [U, R, D, L]
    return 'YES' if helper(0, ans, n, A) else 'NO'

T = int(raw_input())
for i in xrange(1, T+1):
    n, U, R, D, L = map(int, raw_input().split())
    ans = solve(n, U, R, D, L)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
