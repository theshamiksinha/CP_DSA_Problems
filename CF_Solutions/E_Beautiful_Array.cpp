#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

void solve() {
    int row, col;
    cin >> row >> col;
    vector<int> arr(row);
    lp(0, row){
        cin >> arr[i];
    }
    
    map<int, set<int>> mp;
    for(int x : arr) {
        if(mp[x % col].find(x) != mp[x % col].end()) {
            mp[x % col].erase(x);
        } else {
            mp[x % col].insert(x);
        }
    }
    
    int cnt = 0, val = -1;
    for(auto x : mp) {
        int sz = x.second.size();
        if(sz % 2) {
            cnt++;
            val = x.first;
        }
    }
    
    if(cnt > 1) {
        cout << -1 << endl;
        return;
    }
    
    int ans = 0;
    for(auto x : mp) {
        if(x.first == val) continue;
        while(x.second.size() > 0) {
            int b = *x.second.begin();
            x.second.erase(b);
            if(x.second.size() == 0){
                break;
            }
            int tp = *x.second.begin();
            x.second.erase(tp);
            ans += (tp - b) / col;
        }
    }
    
    if(cnt) {
        vector<int> v;
        for(int x : mp[val]) v.push_back(x);
        int m = v.size();
        if(m == 1) {
            cout << ans << endl;
            return;
        }
        vector<int> pref(m, 0), suf(m, 0);
        pref[1] = v[1] - v[0];
        for(int i = 3; i < m; i += 2) {
            pref[i] = v[i] - v[i - 1] + pref[i - 2];
        }
        suf[m - 2] = v[m - 1] - v[m - 2];
        for(int i = m - 4; i >= 0; i -= 2) {
            suf[i] = v[i + 1] - v[i] + suf[i + 2];
        }
        int maxi = LLONG_MAX;
        for(int i = 0; i < m; i += 2) {
            int x = 0;
            if(i > 0) x += pref[i - 1];
            if(i + 1 < m) x += suf[i + 1];
            maxi = min(maxi, x);
        }
        ans += maxi / col;
    }
    cout << ans << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while(x--){
        solve();
    }
}