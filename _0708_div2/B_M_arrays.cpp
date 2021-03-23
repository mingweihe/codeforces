#include <bits/stdc++.h>

using namespace std;
const int maxn = 1e5+1;
int n, m, a[maxn], rem[maxn];

void solve(){
    cin >> n >> m;
    memset(rem, 0, sizeof(rem));
    for(int i = 0; i < n; ++i){
        cin >> a[i];
        rem[a[i] % m]++;
    }
    int ans = 0;
    ans += bool(rem[0]);
    rem[0] = 0;
    for(int i = 0; i < n; ++i){
        int remainder = a[i] % m;
        if(rem[remainder] == 0) continue;
        int nx = m - remainder;
        if(rem[nx] < rem[remainder])
            nx = remainder;
        while(rem[nx]){
            rem[nx]--;
            nx = m - nx;
        }
        ans += 1;
    }
    cout << ans << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t, i = 1;
    cin >> t;
    while(t--){
        solve();
        i++;
    }
}
