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
    string str; cin >> str;

    vector<int> track(26, 0);

    lp(0, n){
        track[str[i] - 'a'] = 1;
    }

    string ok = "abcdefghijklmnopqrstuvwxyz";

    vector<char> key1, key2;

    lp(0, 26){
        if(track[i]){
            key2.push_back(ok[i]);
        }
    }

    key1 = key2;

    reverse(key2.begin(), key2.end());

    map<char, char> m;

    lp(0, key1.size()){
        m[key1[i]] = key2[i];
    }

    lp(0, n){
        cout << m[str[i]];
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