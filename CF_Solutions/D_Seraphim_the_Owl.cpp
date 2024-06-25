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
    int n,m;cin>>n>>m;
    vector<int> cost1(n);
    for(int i = 0; i < n; i++) {
        cin>>cost1[i];
    }
    vector<int> cost2(n);
    for(int i = 0; i < n; i++) {
        cin>>cost2[i];
    }
 
    vector<int> pref(n);
 
    int curr = 0;
    for(int i = n-1;i>=0;i--){
        pref[i] = curr + cost1[i];
        curr += min(cost1[i],cost2[i]);
    }
 
    int ans = LLONG_MAX;
 
    for(int i = m-1;i>=0;i--){
        ans = min(ans,pref[i]);
    }
 
    cout<<ans<<endl; 
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