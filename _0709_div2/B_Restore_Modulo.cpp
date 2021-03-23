#include <bits/stdc++.h>

using namespace std;

int n, a[200005];

void solve(){
    cin >> n;
    int maxi = INT_MIN;
    for(int i = 1; i <= n; ++i){
        cin >> a[i];
        maxi = max(maxi, a[i]);
    }
    unordered_set<int> st;
    for(int i = 2; i <= n; ++i){
        st.insert(a[i] - a[i-1]);
    }
    if(st.size() > 2){
        cout << -1 << '\n';
        return;
    }else if(st.size() == 1 || n == 1){
        cout << 0 << '\n';
        return;
    }
    int m = 0, cnt0 = 0, cnt1 = 0, c;
    for(int x: st){
        m += abs(x);
        if(x > 0){
            c = x;
            cnt0++;
        }
        if(x < 0){
            cnt1++;
        }
    }
    if(cnt0 == 1 && cnt1 == 1 && m >= maxi){
        cout << m << ' ' << c << '\n';
    }else{
        cout << -1 << '\n';
    }
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