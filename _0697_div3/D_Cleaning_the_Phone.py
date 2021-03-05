def solve(n, m, A, B):
    ans = 0
    ones, twos = [], []
    for i in xrange(n):
        if B[i] == 1: ones += A[i],
        else: twos += A[i],
    ones.sort()
    twos.sort()
    i, j = len(ones)-1, len(twos)-1
    while m > 0 and (i >= 0 or j >= 0):
        if i >= 0 and ones[i] >= m:
            m -= ones[i]
            ans += 1
            break
        mem1, mem2 = float('-inf'), float('-inf')
        if i == 0: mem1 = ones[i]
        elif i > 0: mem1 = ones[i] + ones[i-1]
        if j >= 0: mem2 = twos[j]
        if mem1 >= mem2:
            m -= ones[i]
            i -= 1
            ans += 1
        else:
            m -= mem2
            j -= 1
            ans += 2
    return -1 if m > 0 else ans

for _ in xrange(int(raw_input())):
    n, m = map(int, raw_input().split())
    A = map(int, raw_input().split())
    B = map(int, raw_input().split())
    print solve(n, m, A, B)
