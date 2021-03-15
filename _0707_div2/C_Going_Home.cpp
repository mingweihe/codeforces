#include <bits/stdc++.h>
using namespace std;

int n;
int a[200001], x[5000001], y[5000001];

// pigeonhole principle, O(n) time return for qualified input data
void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    memset(x, 0, sizeof(x));
    memset(y, 0, sizeof(y));
    for(int i = 1; i < n; ++i){
        for(int j = i+1; j <= n; ++j){
            int s = a[i] + a[j];
            if(x[s] && x[s] != i && x[s] != j && y[s] != i && y[s] != j){
                cout << "YES" << '\n';
                cout << x[s] << ' ' << y[s] << ' ' << i << ' ' << j << '\n';
                return;
            }
            x[s] = i, y[s] = j;
        }
    }
    cout << "NO" << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
