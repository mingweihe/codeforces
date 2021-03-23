#include <bits/stdc++.h>

using namespace std;

int n, a[101];

void solve(){
    cin >> n;
    memset(a, 0, sizeof(a));
    for(int i = 0; i < n; ++i){
        int x;
        cin >> x;
        a[x] += 1;
    }
    for(int i = 0; i <= 100; ++i){
        if(a[i]){
            cout << i << ' ';
            a[i]--;
        }
    }
    for(int i = 0; i <= 100; ++i){
        while(a[i]){
            cout << i << ' ';
            a[i]--;
        }
    }
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
