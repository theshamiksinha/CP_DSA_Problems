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
    int n, x, y; cin >> n >> x >> y;

    vector<int> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    map<pair<int, int>, int> mp;

    int ans = 0;
    
    for(int i = 0; i < n; i++) {
        
        int a = arr[i];
        int p1 = a%x;
        int p2 = a%y;
        
        int q1 = x - p1;
        int q2 = y + p2;

        if(mp.find({q1, q2}) != mp.end()){
            ans+=mp[{q1,q2}];
        }
        if(mp.find({q1-x, q2-y}) != mp.end()){
            ans+=mp[{q1-x, q2-y}];
        }
        if(mp.find({q1, q2-y}) != mp.end()){
            ans+=mp[{q1, q2-y}];
        }
        if(mp.find({q1-x, q2}) != mp.end()){
            ans+=mp[{q1-x, q2}];
        }

        mp[{p1, p2}]++;

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