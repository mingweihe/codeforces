def solve(n, A, B):
    rows_flips = [0] * n
    for i in xrange(n):
        rows_flips[i] = A[i][0] != B[i][0]
    for j in xrange(1, n):
        cnt = 0
        for i in xrange(n):
            cnt += (A[i][j] != B[i][j]) ^ rows_flips[i]
        if cnt != 0 and cnt != n:
            return 'NO'
    return 'YES'

for _ in xrange(int(raw_input())):
    n = int(raw_input())
    A, B = [], []
    for _ in xrange(n):
        A += raw_input(),
    raw_input()
    for _ in xrange(n):
        B += raw_input(),
    print solve(n, A, B)
