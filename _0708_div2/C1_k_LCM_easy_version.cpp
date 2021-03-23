#include <bits/stdc++.h>

using namespace std;

int n, k;
void solve(){
    cin >> n >> k;
    int ans[3];
    if(n == 3){
        ans[0] = ans[1] = ans[2] = 1;
    }else{
        if(n & 1){
            ans[0] = 1;
            ans[1] = ans[2] = (n-1) / 2;
        }else{
            if((n/2 & 1) == 0){ // == has higher priority than &, or n/2 % 2 == 0 
                ans[0] = n/2;
                ans[1] = ans[2] = n/4;
            }else{
                ans[0] = 2;
                ans[1] = ans[2] = n/2 - 1;
            }

        }
    }
    for(int i = 0; i < k; ++i)
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
