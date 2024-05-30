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

    int n, q; cin >> n >>q;
    vector<int> arr(n);

    for(int i = 0; i < n; i ++){
        cin >> arr[i];
    }

    vector<int> pref(n+1, 0);

    for(int i = 1 ; i < pref.size(); i++){
        pref[i] = pref[i-1] ^ arr[i-1];
    } 

    while(q--){
        int a, b; cin >> a >> b;

        cout <<( pref[b] ^ pref[a-1]) << endl;
    }
    
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