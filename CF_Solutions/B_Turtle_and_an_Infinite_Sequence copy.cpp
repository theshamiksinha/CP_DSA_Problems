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
    int lo = max(n-m, 0LL);
    int hi = n+m;
    
    int diff = hi - lo;

    int ans = 0;

    for(int i = 0; i < 31; i++){

        int range = 1<<i;   // range over which 0, 1 alternates

        if(diff >= range){
            ans |= 1 << i;  // if range over which 0, 1 alternates is smaller than diff b/w lo and hi
                            // we set that bit, as it will be 1 atleast one time in the given range of numbers from lo to hi
        }else{
            int bit = lo & 1 << i;
            bit |= hi & 1 << i;
                            // checking whether bit is either set in lo or hi if diff not greater than range
            ans |= bit;
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