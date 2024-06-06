#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

void solve(){
    int n; cin >> n;
    vector<int> a(n), b(n);
    lp(0, n){
        cin >> a[i];
    }
    lp(0, n){
        cin >> b[i];
    }

    int m; cin >> m;
    vector<int> d(m);
    lp(0, m){
        cin >> d[i];
    }

    bool flag = 0;
    lp(0, n){
        if(b[i] == d.back()){
            flag = true;
            break;
        }
    }
    
    map<int, int> mp;

    lp(0, m){
        mp[d[i]]++;
    }

    lp(0, n){
        if(a[i] != b[i] &&  mp[b[i]] == 0) {
            no;
            return;
        }else if(a[i] != b[i]){
            mp[b[i]]--;
        }
    }
 
    if(flag){
        yes;
        return;
    }  
    no; 

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