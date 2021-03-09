nums = {'0': '0', '1': '1', '2': '5', '5': '2', '8': '8'}

def fmt(x):
    return str(x).rjust(2, '0')

def is_valid(hh, mm, h, m):
    md = ''
    for d in (fmt(hh) + fmt(mm))[::-1]:
        if d not in nums: return False
        md += nums[d]
    return 0 <= int(md[:2]) < h and 0 <= int(md[2:]) < m
    
def solve(h, m, time):
    hh, mm = map(int, time.split(':'))
    while not is_valid(hh, mm, h, m):
        mm = (mm + 1) % m
        if mm == 0:
            hh = (hh + 1) % h
    return fmt(hh) + ':' + fmt(mm)

for _ in xrange(int(raw_input())):
    h, m = map(int, raw_input().split())
    time = raw_input().strip()
    print solve(h, m, time)
