#include <iostream>
#include <vector>

using namespace std;

const int maxn = 1e5;

string s;
vector<vector<int>> pre(maxn+1, vector<int>(26));

int main(){
    int t, n, k;
    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> s;
        if(n % k){
            cout << -1 << endl;
            continue;
        }
        fill(begin(pre[0]), end(pre[0]), 0);
        for(int i = 1; i <= n; ++i){
            char c = s[i-1];
            for(int j = 0; j < 26; ++j){
                pre[i][j] = pre[i-1][j] + (c - 'a' == j);
            }
        }
        int ok = 1;
        for(int i = 0; i < 26; ++i)
            ok &= pre[n][i] % k == 0;
        if(ok){
            cout << s << endl;
            continue;
        }
        for(int i = n-1; i >= 0; --i){
            int rem = n - i - 1;
            ok = 0;
            for(int j = s[i] - 'a' + 1; j < 26; ++j){
                pre[i][j]++;
                int need = 0;
                for(int y = 0; y < 26; ++y)
                    need += (k - pre[i][y] % k) % k;
                pre[i][j]--;
                if(need > rem) continue;
                if((rem-need)%k) continue;
                pre[i][j]++;
                s[i] = (char) (j+'a');
                int idx = i+1;
                for(int x = 0; x < rem - need; ++x)
                    s[idx++] = 'a';
                for(int x = 0; x < 26; ++x){
                    for(int z = 0; z < (k - pre[i][x] % k) % k; ++z)
                        s[idx++] = (char) ('a' + x);
                }
                cout << s << endl;
                ok = 1;
                break;
            }
            if(ok) break;
        }
    }
    return 0;
}
