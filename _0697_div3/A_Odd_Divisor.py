def solve(N):
    while N % 2 == 0: N /= 2
    if N == 1: return 'NO'
    return 'YES'

T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    print solve(N)
