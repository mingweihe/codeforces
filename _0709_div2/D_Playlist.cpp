#include <bits/stdc++.h>

using namespace std;

int n, x;

set<pair<int, int>>::iterator pnext(set<pair<int, int>>::iterator& it, set<pair<int, int>>& plist){
    if(next(it) == plist.end()){
        return plist.begin();
    }else{
        return next(it);
    }
}

// brute force TLE solution
void solve(){
    cin >> n;
    set<pair<int, int>> plist;
    for(int i = 1; i <= n; ++i){
        cin >> x;
        plist.insert(make_pair(i, x));
    }
    if(n == 1){
        if(x == 1){
            cout << 1 << ' ' << 1 << '\n';
        }else{
            cout << 0 << '\n';
        }
        return;
    }
    vector<int> ans;
    set<pair<int, int>>::iterator pt = plist.begin();
    set<pair<int, int>>::iterator it = next(plist.begin());
    set<pair<int, int>>::iterator tmp, nx, nnx;
    int size = n;
    while(true){
        // cout << "loop #" << i++ << ' ' << (*pt).second << ' ' << (*it).second << endl; 
        if(gcd((*pt).second, (*it).second) == 1){
            ans.push_back((*it).first);
            nx = pnext(it, plist);
            if(it == nx){
                break;
            }
            tmp = it;
            nnx = pnext(nx, plist);
            if(it == nnx){
                it = pt;
            }else{
                pt = nx;
                it = nnx;
            }
            plist.erase(tmp);
        }else{
            if(it == plist.begin()){
                if(size == plist.size()){
                    break;
                }
                size = plist.size();
            }
            pt = it;
            it = pnext(it, plist);
        }
    }
    cout << ans.size() << ' ';
    for(int x: ans) cout << x << ' ';
    cout << '\n';
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
