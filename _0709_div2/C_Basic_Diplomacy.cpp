#include <bits/stdc++.h>

using namespace std;

int n, m, k, x, cnt[100005], ans[100005];
vector<vector<pair<int, int>>> a;

void solve(){
    cin >> n >> m;
    int up = (m+2-1)/2;
    for(int i = 0; i < m; ++i){
        vector<pair<int, int>> row;
        cin >> k;
        for(int j = 0; j < k; ++j){
            cin >> x;
            row.push_back(make_pair(x, i));
        }
        a.push_back(row);
    }
    sort(a.begin(), a.end(), [](vector<pair<int, int>> x, vector<pair<int, int>> y){
        return x.size() < y.size();
    });
    memset(cnt, 0, sizeof(cnt));
    bool ok;
    for(int i = 0; i < m; ++i){
        ok = false;
        for(pair<int, int> p: a[i]){
            if(cnt[p.first] == up) continue;
            cnt[p.first]++;
            ans[p.second] = p.first;
            ok = true;
            break;
        }
        if(!ok) break;
    }
    a.clear();
    if(!ok){
        cout << "NO" << "\n";
    }else{
        cout << "YES" << "\n";
        for(int i = 0; i < m; ++i){
            cout << ans[i] << ' ';
        }
        cout << '\n';
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