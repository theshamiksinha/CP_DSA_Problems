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
    int n; cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));
    if(grid[n-1][n-1] == '.'){
        dp[n-1][n-1] = 1;
    }else{
        dp[n-1][n-1] = 0;
    }

    for(int i = n-1; i >= 0; i--){
        for(int j = n-1; j >= 0; j--){
            
            if(i == n-1 && j == n-1){
                continue;
            }
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }else{

                if(i < n-1){
                    dp[i][j] += dp[i+1][j];
                }else{
                    dp[i][j] += 0;
                }

                if(j<n-1){
                    dp[i][j] += dp[i][j+1];
                }else{
                    dp[i][j] += 0;
                }

                dp[i][j] %= MOD;
            } 
        }
    }

    cout << dp[0][0] << endl;
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