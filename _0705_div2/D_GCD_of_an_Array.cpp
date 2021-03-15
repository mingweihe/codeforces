#include <iostream>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;
typedef long long ll;
const int maxn = 2e5 + 1;
const int mod = 1e9 + 7;
multiset<int> ms[maxn];
unordered_map<int, int> mp[maxn];
vector<int> prime_factors[maxn];

vector<int> get_primes(int num){
    if(!prime_factors[num].empty())
        return prime_factors[num];
    vector<int> ans;
    int i, tmp;
    tmp = num;
    i = 2;
    while(i * i <= tmp){
        while(tmp % i == 0){
            ans.push_back(i);
            tmp /= i;
        }
        ++i;
    }
    if(tmp > 1) ans.push_back(tmp);
    prime_factors[num] = ans;
    return ans;
}

ll qpow(ll x,ll y){
    ll res = 1;
    while(y){
        if(y & 1) res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

int main(){
    ll ans = 1;
    int n, q, num;
    cin >> n >> q;
    for(int i = 1; i <= n; ++i){
        cin >> num;
        vector<int> ps = get_primes(num);
        for(int p: ps) mp[i][p]++;
    }
    unordered_map<int, int>::iterator it;
    for(int i = 1; i <= n; ++i){
        for(it = mp[i].begin(); it != mp[i].end(); ++it){
            ms[it->first].insert(it->second);
            if(ms[it->first].size() == n)
                ans = ans * qpow(it->first, *ms[it->first].begin()) % mod;
        }
    }

    int i, x, power_i_p;
    for(int j = 0; j < q; ++j){
        cin >> i >> x;
        vector<int> ps = get_primes(x);
        for(int p: ps){
            if(mp[i].find(p) == mp[i].end()){
                ms[p].insert(1);
                if(ms[p].size() == n)
                    ans = ans * p % mod;
            }else{
                power_i_p = mp[i][p];
                ms[p].erase(ms[p].find(power_i_p));
                ms[p].insert(power_i_p + 1);
                if(ms[p].size() == n && *ms[p].begin() == power_i_p + 1)
                    ans = ans * p % mod;
            }
            mp[i][p]++;
        }
        cout << ans << endl;
    }
}
