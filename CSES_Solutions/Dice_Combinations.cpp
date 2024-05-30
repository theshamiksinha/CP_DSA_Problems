#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

int mod = 1e9 + 7;


void solve(){
    
    int n; cin >> n; 

    vector<int> dp(n+1, 0);

    dp[0] = 1;

    for(int i = 1; i < n+1; i++){

        for(int j=1; j <=6; j++){

            if(i-j >= 0){
                dp[i] += dp[i-j]%mod;
            }
        }
    }
    
    int ans = dp[n]%mod;

    cout << ans%mod << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    // cin >> x;
    while(x--){
        solve();
    }
}