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

    vector<int> dp(n+1); 

    for(int i = 0; i < n+1; i++){
        if(i <= 9){
            dp[i] = 1;
        }else{
            break;
        }
    }

    for(int i = 10; i < n+1; i++){

        int maxi = INT_MIN;
        int temp = i;
        while(temp!=0){
            int digit = temp%10;
            temp = temp/10;
            maxi = max(maxi, digit);
        } 

        dp[i] += 1 + dp[i-maxi];
    }

    cout << dp[n] << endl;
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