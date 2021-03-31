#include <bits/stdc++.h>

using namespace std;

int n, k, mod = 1e9+7;
int cache[1005][1005][2];

int dfs(int i, int k, int d){
    if(k == 1) return 0;
    if((i >= n && d == 1) || (i <= -1 && d == 0)) return 0;
    if(cache[i][k][d] != -1) return cache[i][k][d];
    int ans = 0;
    if(d == 1){
        ans = dfs(i+1, k, d) + dfs(i-1, k-1, d^1) + 1;
    }else{
        ans = dfs(i-1, k, d) + dfs(i+1, k-1, d^1) + 1;
    }
    ans %= mod;
    cache[i][k][d] = ans;
    return ans;
}

void solve(){
    cin >> n >> k;
    memset(cache, -1, sizeof(cache));
    cout << dfs(0, k, 1) + 1 << '\n';

}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
        solve();
}