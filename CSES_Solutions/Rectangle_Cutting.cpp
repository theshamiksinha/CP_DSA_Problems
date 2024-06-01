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

    int a, b; cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));

    for(int i = 1; i <= a; i++){
        dp[i][1] = i-1;
    }
    for(int i = 1; i <= b; i++){
        dp[1][i] = i-1;
    }
    for(int i = 0; i<= min(a, b); i++){
        dp[i][i] = 0;
    }

    for(int i = 2; i <= a; i++){
        for(int j = 2; j <= b; j++){

            for(int t = 1; t <= j-1; t++){
                dp[i][j] = min(dp[i][j], 1 + dp[i][t] + dp[i][j-t]);   // vertical cuts 
            }

            for(int t = 1; t <= i-1; t++){
                dp[i][j] = min(dp[i][j], 1 + dp[t][j] + dp[i-t][j]);   // horizontal cuts 
            }

        }
    }

    cout << dp[a][b] << endl;
    
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