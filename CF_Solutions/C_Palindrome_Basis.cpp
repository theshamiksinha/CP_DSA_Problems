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

bool isPal(int num){
    string s = to_string(num);
    string temp = s;
    reverse(temp.begin(), temp.end());

    return s == temp;
}

void solve(vector<vector<int>> &dp){
    
    int n; cin >> n;

    cout << (dp[n][499]) << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;

    vector<int> pals;

    int n = 40002;
    int m = 502;
    for(int i = 0; i <= n; i++){
        if(isPal(i)){
            pals.push_back(i);
        }
    }  
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
 
    for (int j = 0; j <= m; j++) {
        dp[0][j] = 1;
    } 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            dp[i][j] = dp[i][j - 1]; // Exclude the j-th palindrome
            if (i >= pals[j - 1]) {
                dp[i][j] = (dp[i][j] + dp[i - pals[j - 1]][j]) % MOD; // Include the j-th palindrome
            }
        }
    }
    while(x--){
        solve(dp);
    }
}