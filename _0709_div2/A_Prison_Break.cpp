#include <bits/stdc++.h>

using namespace std;


int a, b;

void solve(){
    cin >> a >> b;
    int ans = a * b;
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