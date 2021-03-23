#include <bits/stdc++.h>

using namespace std;

int n, k1, k2;
int w, b;

void solve(){
    cin >> n >> k1 >> k2;
    cin >> w >> b;
    int k1w = k1, k2w = k2;
    while(w && k1w + k2w >= 2){
        if(k1w > k2w){
            k1w -= 2;
        }else if(k1w < k2w){
            k2w -= 2;
        }else{
            k1w--;
            k2w--;
        }
        w--;
    }
    int k1b = n-k1, k2b = n-k2;
    while(b && k1b + k2b >= 2){
        if(k1b > k2b){
            k1b -= 2;
        }else if(k1b < k2b){
            k2b -= 2;
        }else{
            k1b--;
            k2b--;
        }
        b--;
    }
    if(w==0 && b==0) cout << "YES" << '\n';
    else cout << "NO" << '\n';
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
