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
    int n, m; cin >> n >> m;
    vector<int> arr(n);

    lp(0, n){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(int i = 1; i < m+1; i++){
        if(arr[0] == 0 || arr[0] == i){
            dp[1][i] = 1;
        }
    }

    for(int size = 2; size < n+1; size++){
        for(int k = 1; k < m+1; k++){

            if(arr[size-1] != 0 && arr[size-1] != k){
                dp[size][k] = 0;
                continue;
            }

            if(k > 1 && k < m){
                dp[size][k] = dp[size-1][k-1] + dp[size-1][k] +dp[size-1][k+1];
            }else if(k == 1){
                dp[size][k] = dp[size-1][k] +dp[size-1][k+1];
            }else{
                dp[size][k] = dp[size-1][k-1] + dp[size-1][k];
            }
            dp[size][k] %= MOD;
        }
    }

    int ans = 0;
    lp(1, m+1){
        ans += dp[n][i]%MOD;
    }
    ans %= MOD;

    cout << ans << endl;
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