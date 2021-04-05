#include <bits/stdc++.h>

// Lesson learned: consider using stack whenever it's a brackets problem
using namespace std;
int n;
string s, a, b;

void solve(){
    cin >> n >> s;
    int al = 1, bl = 1, rem;
    int ones = 0, zeros = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] == '1') ones++;
        else zeros++;
    }
    if(ones % 2 || zeros % 2 || s[0] != '1' || s.back() != '1'){
        cout << "NO" << '\n';
        return;
    }
    a = "", b = "";
    for(int i = 0; i < n; ++i){
        if(s[i] == '1'){
            if(ones){
                a += '(';
                b += '(';
                ones -= 2;
            }else{
                a += ')';
                b += ')';
            }
        }else{
            if(zeros % 2 == 0){
                a += '(';
                b += ')';
            }else{
                a += ')';
                b += '(';
            }
            zeros -= 1;
        }
    }
    cout << "YES" << '\n';
    cout << a << '\n';
    cout << b << '\n';
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