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
    vector<int> points(n);

    lp(0, n){
        cin >> points[i];
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int i = n-1; i >= 0; i--){
        for(int j = 0; j <= n-1; j++){

            if( i == j){
                dp[i][j] = points[i];
            }else if(j - i == 1){
                dp[i][j] = max(points[i], points[j]);
            } 
            else if(i < j){

                int case1 = 0;
                int case2 = 0;

                if(i+2 < n){
                    case1 = points[i] + min(dp[i+2][j] , dp[i+1][j-1]);
                }
                if(j-2 >= 0){
                    case2 = points[j] + min(dp[i+1][j-1] , dp[i][j-2]);
                }

                dp[i][j] = max(case1, case2);
            }
        }
    }

    cout << dp[0][n-1] << endl;


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