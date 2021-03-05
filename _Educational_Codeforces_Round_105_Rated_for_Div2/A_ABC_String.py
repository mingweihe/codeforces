from collections import Counter
def solve(A):
    if A[0] == A[-1]: return 'NO'
    s = {A[0]: '(', A[-1]: ')'}
    cnt = Counter(A)
    stack = []
    for c in A:
        if not stack:
            if c not in s: s[c] = '('
            stack += s[c],
        else:
            if c not in s:
                if cnt[A[0]] > cnt[A[-1]]: s[c] = ')'
                elif cnt[A[0]] < cnt[A[-1]]: s[c] = '('
                else: return 'NO'
            if stack[-1] == '(' and s[c] == ')': stack.pop()
            else: stack += s[c],
    return 'YES' if not stack else 'NO'

T = int(raw_input())
for i in xrange(1, T+1):
    A = raw_input().strip()
    ans = solve(A)
    print '{}'.format(ans)
    # print 'case:{}->{}'.format(i, ans)
