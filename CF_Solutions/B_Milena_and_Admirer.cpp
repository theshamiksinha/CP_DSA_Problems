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
    
    int i = n-2;
    int splits = 0;
    int min = arr[n-1];
    while(i >= 0){
        if (arr[i] > min) {
            int q = arr[i] / min;
            int r = arr[i] % min;
            if (r == 0) {
                splits += q - 1;
            } else {
                splits += q;
                int x = ceil(arr[i] / (1.0*min));
                min = arr[i] / x;
            }
        } else {
            min = arr[i];
        }
        i--;
    }

    cout << splits << endl;
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