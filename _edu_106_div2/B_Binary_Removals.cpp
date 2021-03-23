#include <bits/stdc++.h>

using namespace std;

int dp[100][2];
string s;

void solve(){ 
    cin >> s;
    int n = s.size();
    dp[0][0] = dp[0][1] = 1;
    for(int i = 1; i < n; ++i){
        if(s[i] == '1'){
            dp[i][1] = dp[i-1][0] || dp[i-1][1];
            dp[i][0] = dp[i-1][1];
        }else{
            if(s[i-1] == '0'){
                dp[i][0] = dp[i-1][1];
                dp[i][1] = dp[i-1][1];
            }else{
                dp[i][0] = dp[i-1][1];
                if(i==1){
                    dp[i][1] = 1;
                    continue;
                }
                if(s[i-2] == '1') dp[i][1] = 0;
                else dp[i][1] = dp[i-2][1];
            }
        }
    }
    if(dp[n-1][0] or dp[n-1][1]) cout << "YES" << '\n';
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
