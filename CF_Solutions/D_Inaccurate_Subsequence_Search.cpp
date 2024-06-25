#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

void solve() {
    int n, m, k;
    cin >> n >> m >> k; 

    vector<int> a(n), b(m);
    map<int, int> mp;
    
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++) {
        cin >> b[i];
        mp[b[i]]++;
    } 

    map<int, int> in;
    int cnt = 0;

    for(int i = 0; i < m; i++){
        if(in[a[i]] < mp[a[i]]){
            cnt++;
        }
        in[a[i]]++;
    }
    int ans = 0;
    if(cnt >= k){
        ans++;
    }

    for(int i = m; i < n; i++){
        if(in[a[i-m]] <= mp[a[i-m]]){
            cnt--;
        }
        in[a[i-m]]--;
        if(in[a[i]] < mp[a[i]]){
            cnt++;
        }
        in[a[i]]++;
        if(cnt >= k){
            ans++;
        }
    }
     
    cout << ans << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while (x--) {
        solve();
    }
}
