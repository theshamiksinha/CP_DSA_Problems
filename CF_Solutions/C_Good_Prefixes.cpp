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
    vector<int> pref(n+1, 0);

    lp(1, n+1){
        pref[i] = pref[i-1] + arr[i-1];
    }

    int maxi = INT_MIN;
    int cnt = 0;
    lp(0, n){
        if(arr[i] > maxi){
            maxi = arr[i];
        }
        if(pref[i+1]-maxi == maxi){
            cnt++;
        }
    }

    cout << cnt << endl;
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