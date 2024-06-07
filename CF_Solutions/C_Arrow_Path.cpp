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

bool func(int i, int j, vector<vector<int>> &path, vector<vector<int>> &dp){
    int n = path[0].size();

    if( i < 0 || i > 1 || j < 0 || j > n-1){
        return false;
    }
    else if(j != 0 || i != 0){
        j += path[i][j];
        if( j < 0 || j > n-1){
            return false;
        }
    }

    if(i == (1) && j == (n-1)){
        return true;
    }

    if (dp[i][j] != -1) {
        return dp[i][j];
    }

    dp[i][j] = false;

    int case1 = func(i+1, j,  path, dp);

    int case2 = func(i-1, j,  path, dp);

    int case3 = func(i, j+1, path, dp);

    int case4 = func(i, j-1,  path, dp); 

    return dp[i][j] = case1 || case2 || case3 || case4;
}

void solve(){
    int n; cin >> n;
    vector<vector<int>> path(2, vector<int>(n));

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++){
            char p ; cin >> p;
            if(p == '<'){
                path[i][j] = -1;
            }else{
                path[i][j] = 1;
            } 
        }
    }

    vector<vector<int>> dp(2, vector<int>(n, -1)); 

    bool ans = func(0, 0, path, dp);

    if(ans){
        yes;
    }else{
        no;
    } 
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