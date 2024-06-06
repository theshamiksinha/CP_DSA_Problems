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

    vector<int> nums(7, 0);
    string let = "ABCDEFG";

    string s ; cin >> s;

    lp(0, n){
        nums[s[i]-'A']++;
    }

    int ans = 0;
    lp(0, 7){
        if(nums[i] > m){
            continue;
        }else{
            ans += (m - nums[i]);
        }
    }

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