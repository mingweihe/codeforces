#include <bits/stdc++.h>

using namespace std;

int n, k, mod = 1e9+7;
int cache[1005][1005];

int dfs(int i, int k){
    if(i == 0 || k == 1) return 1;
    if(cache[i][k] != -1) return cache[i][k];
    int ans = dfs(i-1, k) + dfs(n-i, k-1);
    ans %= mod;
    cache[i][k] = ans;
    return ans;
}

void solve(){
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << dfs(n, k) << '\n';
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}
