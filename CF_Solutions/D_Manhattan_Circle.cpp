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
    int n, m; cin >>n>>m;
    vector<string> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    vector<vector<int>> p;

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j] == '#'){
                p.push_back({i+1, j+1});
            }
        }
        
    }

    // sort(p.begin(), p.end());

    cout << p[p.size()/2][0] << " " << p[p.size()/2][1] << endl;
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