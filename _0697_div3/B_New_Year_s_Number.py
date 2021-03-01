def solve(N):
    M, R = divmod(N, 2020)
    if R <= M: return 'YES'
    return 'NO'

T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    print solve(N)
