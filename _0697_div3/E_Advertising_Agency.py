from collections import Counter

def comb(n, k):
    ans = 1
    for i in xrange(k):
        ans *= n
        ans /= i + 1
        n -= 1
    return ans

def solve(n, k, A):
    mod = 10**9 + 7
    cnts = Counter(A)
    A.sort(reverse=True)
    nums = sorted(set(A[:k]))
    num_big = 0
    for i in xrange(1, len(nums)):
        num_big += cnts[nums[i]]
    num_last = k - num_big
    return comb(cnts[nums[0]], num_last) % mod

for _ in xrange(int(raw_input())):
    n, k = map(int, raw_input().split())
    A = map(int, raw_input().split())
    print solve(n, k, A)