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
    int n, a, b; cin >> n >> a >> b;
    
    if(b <= a){
        cout << a*n << endl;
        return;
    }

    int req = b - a + 1;
    req = min(n, req);

    int ans = 0;
    ans = (b+1)*req;
    ans -= (req*(req+1))/2;

    cout << ans + (n-req)*a << endl;
 
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