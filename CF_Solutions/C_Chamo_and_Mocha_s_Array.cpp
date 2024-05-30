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
    int n; cin >> n;

    vector<int> arr(n);

    int maxi = INT_MIN;

    lp(0, n){
        cin >> arr[i];
    } 

    lp(1,n-1){
        vector<int> check = {arr[i-1], arr[i], arr[i+1]};
        sort(check.begin(), check.end());
        maxi = max(maxi, check[1]);
    }

    if(maxi == INT_MIN){
        sort(arr.begin(), arr.end());
        cout << arr[n-2] << endl;
        return;
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