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
    int n, k; cin >> n >> k;
    vector<int> arr(n);
    lp(0, n){
        cin >> arr[i];
    }
    vector<int> bitset(31, 0);

    for(int i = 0; i < n; i++){
        int el = arr[i];
        int pos = 0;
        while(pos < 31){
            if((el & (1 << pos)) != 0){
                bitset[pos]++;
            }
            pos++;
        }
    }
    
    for(int i = 30; i >= 0; i--){

        if(k == 0){
            break;
        }

        if(k - (n-bitset[i]) >= 0){
            k -= (n-bitset[i]);
            bitset[i] = n;
        }
    } 
    
    int ans = 0;
    for(int i = 0; i < 31; i++){
        if(bitset[i] >= n){
            ans = (ans | (1 << i));
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