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
    int n, m, k; cin >> n >> m >> k;

    vector<int> arr(n);

    lp(0, n){
        cin >> arr[i];
    }
    
    if(m >= k){
        int mini = INT_MAX;
        for(auto it : arr){
            mini = min(mini, it);
        }

        cout << mini*k << endl;
        return;
    }

    vector<pair<int, int>> copy;
    vector<int> days(n);
    lp(0, n){
        copy.push_back({arr[i], i});
    }
    sort(copy.begin(),  copy.end());

    int minCost = 0;
    int toBuy = k;
    int i = 0;
    int t = toBuy%m;
    while(toBuy > 0){
        if(toBuy != t){
            minCost += m*copy[i].first;
            days[copy[i].second] = m;
            toBuy -= m;
        }else{
            minCost += t*copy[i].first;
            days[copy[i].second] = t;
            toBuy -= t;
        }
        i++;
    }

    int minInflate = 0;
    int preSum = 0;
    lp(0, n){
        minInflate += preSum*days[i];
        preSum += days[i];
    }

    cout << minCost + minInflate << endl;
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