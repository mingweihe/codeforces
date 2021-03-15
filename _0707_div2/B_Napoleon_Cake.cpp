#include <bits/stdc++.h>
using namespace std;

int n;
const int maxn = 2e5+1;
int a[maxn];
int ans[maxn];

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    int lowest = n;
    for(int i = n-1; i >= 0; --i){
        lowest = min(lowest, i - a[i] + 1);
        if(i >= lowest) ans[i] = 1;
        else ans[i] = 0;
    }
    for(int i = 0; i < n; ++i)
        cout << ans[i] << ' ';
    cout << '\n';
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
