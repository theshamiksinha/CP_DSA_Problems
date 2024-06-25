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
    int x, y, z, k; cin >>x >> y >> z >> k;

    int maxi = 0;

    for(int a = 1; a <= x; a++){
        for(int b = 1; b <= y; b++){
            if(k%(a*b) == 0){
                int c = k/(a*b);
                if(c > z){
                    continue;
                }
                int ans = (x - a + 1) * (y - b + 1) * (z - c + 1);
                maxi = max(ans, maxi);
            }
        }
    }

    cout << maxi << endl; 
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