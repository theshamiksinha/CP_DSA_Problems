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
    int n, k, q; cin >> n >> k >> q;
    vector<int> kk(k+1, 0), bb(k+1, 0);

    lp(1, k+1){
        cin >> kk[i];
    }

    lp(1, k+1){
        cin >> bb[i];
    }

    while(q--){
        int quer; cin >> quer;
        // cout << quer << endl;

        int pos = upper_bound(kk.begin(), kk.end(), quer) - kk.begin();

        if(kk[pos-1] == quer){
            cout <<  bb[pos-1] <<" ";
            continue;
        }else{ 

            int ans = bb[pos-1] + ((quer - kk[pos-1])*(bb[pos] - bb[pos-1]))/(kk[pos] - kk[pos-1]);

            cout << ans<<" ";
            continue;
        }
    }

    cout << endl;

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