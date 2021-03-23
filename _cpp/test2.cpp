#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define PI acos(-1)
#define pb push_back
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
const int N = 1e5 + 19;
const int M = 100000;
const ll mod = 1e9 + 7;
const double eps = 1e-12;

ll a[N];
set<ll> st;

int main()
{
    int T;
    cin >> T;
    while(T--)
    {
        int n;
        scanf("%d", &n);
        st.clear();
        ll maxx = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", a + i);
            maxx = max(maxx, a[i]);
            if(i == 0)
                continue;
            st.insert(a[i] - a[i - 1]);
        }
        if(st.size() > 2)
        {
            printf("-1\n");
            continue;
        }
        else if(st.size() == 1 || n == 1)
        {
            printf("0\n");
            continue;
        }
        ll cnt1 = 0, cnt2 = 0;
        ll ans;
        ll m = 0;
        for(auto i : st)
        {
            if(i >= 0)
            {
                ans = i;
                cnt1++;
            }
            else
                cnt2++;
            m += abs(i);
        }
        if(cnt1 == 1 && cnt2 == 1 && m >= maxx)
            printf("%lld %lld\n", m, ans);
        else
            printf("-1\n");
    }
    return 0;
}