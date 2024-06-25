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

#define MOD 998244353;



void solve(){
    int n; cin >> n;
    vector<int> arr(n);

    lp(0, n){
        cin >> arr[i];
    }

    vector<vector<int>> dp(n+1, vector<int>(2, 0));

    //dp[i][1] -> the max sum possible upto the ith index in the array;
    //dp[i][0] = min(min(dp[i-1][0]+arr[i], abs(dp[i-1][0]+arr[i]))  ,   min(dp[i-1][1]+arr[i], abs(dp[i-1][1]+arr[i])) )
    //dp[i][0] = max(max(dp[i-1][0]+arr[i], abs(dp[i-1][0]+arr[i]))  ,   max(dp[i-1][1]+arr[i], abs(dp[i-1][1]+arr[i])) )
    
    for(int i = 1; i <= n; i++){
        dp[i][0] = min(min(dp[i-1][0]+arr[i-1], abs(dp[i-1][0]+arr[i-1]))  ,   min(dp[i-1][1]+arr[i-1], abs(dp[i-1][1]+arr[i-1])) );
        dp[i][1] = max(max(dp[i-1][0]+arr[i-1], abs(dp[i-1][0]+arr[i-1]))  ,   max(dp[i-1][1]+arr[i-1], abs(dp[i-1][1]+arr[i-1])) );
    }

    cout << dp[n][1] << endl;
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