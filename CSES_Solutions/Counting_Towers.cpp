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

vector<vector<int>> dp(1e6+1, vector<int>(2)); // creating outside to save on time by not creating memory again and again(priyansh)

void solve(){
    int n; cin >> n; 
    
    
    dp[n][0] = 1;
    dp[n][1] = 1;

    for(int row = n-1; row >= 0; row--){
        dp[row][0] = (2*dp[row+1][0] + dp[row+1][1])%MOD;
        dp[row][1] = (dp[row+1][0] + 4*dp[row+1][1])%MOD;
    }

    int ans = (dp[1][0] + dp[1][1])%MOD;

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