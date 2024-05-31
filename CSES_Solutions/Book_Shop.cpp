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
    int n, x; cin >> n >>x;
    vector<int> price(n), pages(n);
 
    for(int i = 0; i < n; i++){
        cin >> price[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    } 
    
    vector<int> prevState(x+1); //dp[n][x] == prevState[x]
    prevState[0] = 0;
  
    for(int book = 1; book <= n; book++){
 
        vector<int> currState(x+1); //dp[i][x] == currState[x]
        currState[0] = 0;
        for(int money = 1; money <= x; money++){
 
            if(price[book-1] <= money){
                int case1 = pages[book-1] + prevState[money-price[book-1]];
                int case2 = prevState[money];
 
                currState[money] = max(case1, case2);
            }else{
 
                currState[money] = prevState[money];
            }
        }
 
        prevState = currState;
    }
 
    cout << prevState[x] << endl;
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