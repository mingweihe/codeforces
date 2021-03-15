#include <bits/stdc++.h>
using namespace std;

int n, k, p;
const int maxn = 1e5+1;
int a[100+1][2];
int tmm[100+1];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i][0] >> a[i][1];
    for(int i = 1; i <= n; ++i)
        cin >> tmm[i];
    float ans = 0;
    int ai, bi, bi_1, tmi;
    int st, lt;
    for(int i = 1; i <= n; ++i){
        ai = a[i][0];
        bi = a[i][1];
        bi_1 = a[i-1][1];
        tmi = tmm[i];
        ans += ai - bi_1 + tmi;
        if(i == n) break;
        lt = (float) (bi - ai);
        st = ans + ceil(lt/2.0);
        if(st >= bi) ans = st;
        else ans = bi;
    }
    cout << (int) ans << '\n';
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
