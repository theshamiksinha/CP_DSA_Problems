#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";


void solve(){
    int n, k; cin >> n >> k;

    if(n == 1){
        cout << k << endl;
        return;
    }

    int base = floor(log2(k));

    int val = pow(2, base);

    cout << val - 1 << " " << k - val + 1 << " ";

    lp(0, n-2){
        cout << 0 << " ";
    }

    cout << endl;
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