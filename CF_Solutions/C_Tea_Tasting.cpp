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

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    lp(0, n){
        cin >> a[i];
    }
    lp(0, n){
        cin >> b[i];
    }

    vector<int> pref(n+1, 0);
    for(int i = 1; i < n+1; i++){
        pref[i] = pref[i-1] + b[i-1];
    }

    vector<int> cnt(n+1), add(n+1);
    
    for(int i = 0; i < n; i++){
        int j = upper_bound(pref.begin(), pref.end(), a[i] + pref[i]) - pref.begin() - 1;
        cnt[i] += 1;
        cnt[j] -= 1;
        add[j] += a[i] - pref[j] + pref[i];
    }

    for (int i = 0; i < n; ++i) {
      cout << cnt[i] * b[i] + add[i] << ' ';
      cnt[i + 1] += cnt[i];   
    }

    cout << endl;
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