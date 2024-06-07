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
    vector<int> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    int lc = 1;
    lp(0, n){
        lc=lcm(lc, arr[i]);
    }

    vector<int> ans(n);
    int sum = 0;
    lp(0, n){
        ans[i] = lc/arr[i];
        sum += lc/(arr[i]);
    }

    if(sum/lc*1.0 >= 1){
        cout << -1 << endl;
    }else{
        print(ans);
    }

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