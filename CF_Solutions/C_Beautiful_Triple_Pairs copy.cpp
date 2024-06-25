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
    
    map<vector<int>, int> mp;

    int ans = 0;

    for(int i = 0; i < n-2; i++){

        vector<int> temp = {arr[i], arr[i+1], arr[i+2]};
        int does = 0;
        if(mp.find(temp) != mp.end()){
            does = mp[temp];
        }
        vector<int> copy = temp;
        for(int j = 0; j <= 2; j++){
            copy[j] = 0;
            if(mp.find(copy) != mp.end()){
                ans += mp[copy] - does;
            }
            copy = temp;
        }

        for(int j = 0; j <= 2; j++){
            copy[j] = 0;
            mp[copy]++;
            copy = temp;
        }

        mp[temp]++;

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