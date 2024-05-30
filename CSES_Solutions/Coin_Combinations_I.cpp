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

    int n, x; cin >> n >> x;
    vector<int> coins(n);

    lp(0, n){
        cin >> coins[i];
    }

    vector<int> dp(x+1, 0);
    dp[0] = 1;

    for(int i = 0; i <= x; i++){
        for(auto coin : coins){
            if(i - coin >= 0){
                dp[i] = dp[i] + dp[i-coin];
            }
        }

        dp[i] = dp[i]%mod;
    }

    cout << dp[x]%mod << endl;
    
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    solve();
}