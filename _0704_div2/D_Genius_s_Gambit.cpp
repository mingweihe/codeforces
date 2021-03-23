#include <bits/stdc++.h>

using namespace std;

/** 
 * if k == 0, always qualified, simply output the result
 * otherwise, it should meet the condition of at least having two 1 and one 0, and a + b - 2 >= k
 * x = 1|1***0|***
 * y = 1|0***1|***
 * * means any of 1 or 0 is ok, but it must be the same between x and y.
**/
void solve(){
    int a, b, k;
    cin >> a >> b >> k;
    if(k == 0){
        cout << "Yes" << '\n';
        for(int i = 0; i < b; ++i) cout << 1;
        for(int i = 0; i < a; ++i) cout << 0;
        cout << '\n';
        for(int i = 0; i < b; ++i) cout << 1;
        for(int i = 0; i < a; ++i) cout << 0;
        cout << '\n';
        return;
    }
    if(a < 1 || b < 2 || a + b - 2 < k){
        cout << "No" << '\n';
        return;
    }
    cout << "Yes" << '\n';
    // construct x
    string x = "11", y = "10";
    int common_in_the_middle = k - 1;
    int aa = a - 1, bb = b - 2;
    while(common_in_the_middle){
        while(aa && common_in_the_middle){
            x += '0';
            y += '0';
            aa--;
            common_in_the_middle--;
        }
        while(bb && common_in_the_middle){
            x += '1';
            y += '1';
            bb--;
            common_in_the_middle--;
        }
    }
    x += '0';
    y += '1';
    while(aa--){
        x += '0';
        y += '0';
    }
    while(bb--){
        x += '1';
        y += '1';
    } 
    cout << x << '\n';
    cout << y << '\n';
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();    
}
