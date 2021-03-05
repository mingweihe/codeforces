# Kotlin competation is only for kotlin language, Orz
def solve(N, A):
    ans = []
    s = set()
    for i in xrange(N-1, -1, -1):
        if A[i] in s: continue
        s.add(A[i])
        ans += A[i],
    ans = ans[::-1]
    return ' '.join(map(str, ans))

N = int(raw_input())
A = map(int, (raw_input().split()))
ans = solve(N, A)
print ans
