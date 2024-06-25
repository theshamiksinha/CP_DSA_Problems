#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define lp(a, n) for (int i = a; i < n; i++) 
#define MOD 1000000007; 

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    map<int, int> mp; 
    int ans = 0;

    lp(0, n){
        cin >> arr[i];
        mp[arr[i]]++;
    }
    
    lp(0, n){
        int fi = ~arr[i] & INT_MAX;
        if(mp[arr[i]] == 0){ 
            continue;
        } 
    
        if(mp.find(fi) != mp.end()){
            if(mp[fi] == 0){ 
                ans++;
                mp[arr[i]]--;
                continue;
            }
            ans++;
            mp[fi]--;
            mp[arr[i]]--;
        }else{
            ans++;
            mp[arr[i]]--;
        }
    }

    cout << ans << endl; 
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while (x--)
    {
        solve();
    }
}