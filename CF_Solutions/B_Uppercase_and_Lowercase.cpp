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

    int n = s.size();

    int cnt = 0;

    lp(0, s.size()){
        if('A' <= s[i] && s[i] <= 'Z'){
            cnt++;
        }
    }

    if(cnt > n/2){

        lp(0, n){
            if('a' <= s[i] && s[i] <= 'z'){
                s[i] = s[i]-32;
            }
        }
    } else{

        lp(0, n){
            if('A' <= s[i] && s[i] <= 'Z'){
                s[i] = s[i]+32;
            }
        }
    }


    cout << s << endl;
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    // cin >> x;
    while(x--){
        solve();
    }
}