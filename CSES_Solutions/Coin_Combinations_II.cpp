#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h> 
using namespace std;
#define mod 1000000007;

// #define int long long
// #define no  cout << "No" << endl;
// #define yes cout << "Yes" << endl;
// #define int long long
// #define gcd(a, b) __gcd(a, b)
// #define lcm(a, b) ((a)*(b)/gcd(a, b))
// #define lp(a,n)  for(int i =a; i< n; i++)
// #define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

 
void solve(){
    int n, x; 
    cin >> n >> x;
 
    vector<int> coins(n);
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
 
    for(int i = 0; i <= n; i++){
        dp[i][0] = 1;
    }
 
    for(int size = n-1; size >= 0; size--){
        for(int sum = 0; sum <= x; sum++){
            int ans;
            int coin = coins[size];
            if(coin <= sum){
                ans = dp[size][sum-coin] + dp[size+1][sum];
            }else{
                ans = dp[size+1][sum];
            }
            dp[size][sum] = ans % mod;
        }
    }
 
    cout << dp[0][x] << endl;
}
 
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve(); 
}
