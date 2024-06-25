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
    
    int maxlen = 0;
    int ans = 0;
    for (int j = 2; j <= n; j++)
    {
        int vv = j;
        int len = 1;
        if (len > maxlen)
        {
            ans = j;
        }
        while (vv <= n)
        {
            vv += j;
            len += 1;
            if (vv > n)
            {
                break;
            }
            if(len>maxlen)
            {
                ans=j;
                maxlen=len;
            }
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