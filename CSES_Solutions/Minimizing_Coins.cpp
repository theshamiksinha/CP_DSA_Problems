#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i = a; i < n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

const int INF = 1e9;

int func(int sum, vector<int> &coins, vector<int> &dp) {
    if(sum == 0) {  
        return 0;
    }
    if(sum < 0) { 
        return INF;
    } 

    if(dp[sum] != -1) { 
        return dp[sum];
    } 

    int ans = INF;
    for(int i = 0; i < coins.size(); i++) {
        ans = min(ans, 1 + func(sum - coins[i], coins, dp)); 
    }

    return dp[sum] = ans;
}

void solve() {
    int n, x; 
    cin >> n >> x;
    vector<int> coins(n);
    lp(0, n) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1, INF);

    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        int ans = INT_MAX;
        for(auto coin : coins) {
            if(i - coin >= 0){
                ans = min(ans, 1 + dp[i - coin]); 
            }
        }
        dp[i] = ans;
    }

    int ans = func(x, coins, dp);

    if (ans >= INF) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
