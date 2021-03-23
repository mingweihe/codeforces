#include <bits/stdc++.h>

using namespace std;
#define ll long long
const int maxn = 2e5+5;
ll n, a[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    ll min0 = a[0];
    ll min1 = a[1];
    ll accum0 = a[0];
    ll accum1 = a[1];
    ll cur_best;
    int cnt0 = 1, cnt1 = 1;
    ll ans = (a[0]+a[1]) * n;
    for(int i = 2; i < n; ++i){
        if(i % 2 == 0){
            min0 = min(min0, a[i]);
            cur_best = accum0 + accum1 + min0 * (n-cnt0) + min1 * (n-cnt1);
            cnt0++;
            accum0 += a[i]; 
        }else{
            min1 = min(min1, a[i]);
            cur_best = accum0 + accum1 + min1 * (n-cnt1) + min0 * (n-cnt0);
            cnt1++;
            accum1 += a[i];
        }
        ans = min(ans, cur_best);
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
