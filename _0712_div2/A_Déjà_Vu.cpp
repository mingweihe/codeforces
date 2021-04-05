#include <bits/stdc++.h>

using namespace std;
int n, k, a[100005];
string s;

void solve(){
    cin >> s;
    int i = 0, j = s.size() - 1;
    while(i <= j && s[i] == s[j] && s[i] == 'a'){
        i++;
        j--;
    }
    if(i > j){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    if(s[i] == 'a')
        cout << s.substr(0, i) + 'a' + s.substr(i, s.size()-i) << '\n';
    else
        cout << s.substr(0, j+1) + 'a' + s.substr(j+1, s.size()-j-1) << '\n';
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