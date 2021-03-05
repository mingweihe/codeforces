# numpy is not supported on codeforces
# import numpy as np


def solve(x):
    ## Approach 3, O(N)
    ox = int(x ** (1.0/3))
    for a in xrange(1, ox + 1):
        b = x - a ** 3
        if b in cbrt: return 'YES'
    return 'NO'

    ## Approach 2, binary search, O(N*log(N))
    # for a in xrange(1, 10001):
    #     b = x - a ** 3
    #     if b <= 0: break
    #     l, r = 1, 10000
    #     while l <= r:
    #         mid = l + (r - l >> 1)
    #         cube = mid ** 3
    #         if cube > b: r = mid - 1
    #         elif cube < b: l = mid + 1
    #         else: return 'YES'
    # return 'NO'

    ## Approach 1, brute force, O(N^2)
    # ox = int(x ** (1.0/3))
    # for a in xrange(1, ox + 1):
    #     for b in xrange(a, ox + 1):
    #         summ = a**3 + b**3
    #         if summ > x: break
    #         if summ == x: return 'YES'
    # return 'NO'

T = int(raw_input())
cbrt = {}
for i in xrange(1, 10001):
    cbrt[i ** 3] = i
for i in xrange(1, T+1):
    x = int(raw_input())
    ans = solve(x)
    # print 'case {}: {}'.format(i, ans)
    print ans
