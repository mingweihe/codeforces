def solve(a, b, k):
    if b == 1 and k != 0 or a < k:
        print 'NO'
        return
    print 'YES'
    print '1' * (b-1) + '0' * (a-k) + '1' + '0' * k
    print '1' * (b-1) + '0' * a + '1'

a, b, k = map(int, raw_input().split())
solve(a, b, k)
