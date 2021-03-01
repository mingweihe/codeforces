from collections import Counter


def solve(N, A):
    ans = 0
    cnt = Counter(map(lambda x: x % 3, A))
    avg = len(A) / 3
    maxi = max(cnt.values())
    if maxi == avg: return 0
    for i in xrange(3):
        if cnt[i] == maxi:
            cur_moves = abs(cnt[i]-avg)
            ans += cur_moves
            cnt[(i+1) % 3] += cur_moves
            next_moves = cnt[(i+1) % 3]-avg
            if next_moves >= 0: ans += next_moves
            else: ans += (-next_moves) << 1
            break
    return ans

T = int(raw_input())
for i in xrange(1, T+1):
    N = int(raw_input())
    A = map(int, raw_input().split())
    ans = solve(N, A)
    print '{}'.format(ans)
