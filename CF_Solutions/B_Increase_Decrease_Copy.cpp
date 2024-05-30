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
    int n; cin >>n;

    vector<int> a(n), b(n+1);

    lp(0, n){
        cin >> a[i];
    }

    lp(0, n+1){
        cin >> b[i];
    }

    int last = b[n];

    int mini = INT_MAX;

    int ans = 0;

    lp(0, n){
        ans += abs(a[i] - b[i]); 

        mini = min(mini, abs(last - b[i]));
        mini = min(mini, abs(last - a[i]));

        if((last >= a[i] && last <= b[i]) || (last <= a[i] && last >= b[i])){
            mini = 0;
        }
    }

    lp(0, n){
        if(a[i] == last){
            cout << ans + 1 << endl;
            return;
        }
    }

    lp(0, n){
        if(b[i] == last){
            cout << ans + 1 << endl;
            return;
        }
    }

    cout << ans + mini + 1 << endl;

    
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