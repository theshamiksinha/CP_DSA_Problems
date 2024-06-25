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
    string s; cin >> s;
    if(s[0] != '1'){
        no;
        return;
    }
    if(s.back() <= '8' && s.back() >= '0'){

    }else{
        no;
        return;
    }

    lp(1, s.size()-1){
        if(s[i] <= '9' && s[i] >= '1'){

        }else{
            no;
            return;
        }
    }

    yes;
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