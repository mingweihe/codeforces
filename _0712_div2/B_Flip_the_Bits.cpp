#include <bits/stdc++.h>

using namespace std;
int n, pre1[300005], pre2[300005];
string a, b;

void solve(){
    cin >> n;
    cin >> a >> b;
    pre1[0] = pre2[0] = 0;
    for(int i = 1; i <= n; ++i){
        pre1[i] = pre1[i-1] + (a[i-1] == '1');
        pre2[i] = pre2[i-1] + (b[i-1] == '1');
    }
    bool same = true;
    for(int i = n-1; i >= 0; --i){
        if(a[i] == b[i]){
            same = true;
        }else{
            if(same == true){
                if(pre1[i+1] != pre2[i+1] || pre1[i+1] != i - pre1[i+1] + 1){
                    cout << "NO" << '\n';
                    return;
                }
                same = false;
            }
        }
    }
    cout << "YES" << '\n';
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