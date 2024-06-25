#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a, n) for(int i = a; i < n; i++)
#define print(x) for(auto i: x) { cout << i << " "; } cout << "\n";

#define MOD 1000000007

void solve() {
    int n, k, m; 
    cin >> n >> k >> m;
    string s; 
    cin >> s;

    string ans = "";

    set <char> st;
    for(char x : s){

        st.insert(x);
        if(st.size() == k){
            ans += x;
            st.clear();
            n--;
        }

        if(n == 0){
            break;
        }
    }

    if(n == 0){
        yes;
    }else{
        no;
        char mis;
        for(char c = 'a'; c <= 'z'; c++){
            if(st.find(c) == st.end()){
                mis = c;
                break;
            }   
        }
        while(n--){
            ans += mis;
        }
        cout << ans << endl;
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while (x--) {
        solve();
    }
}
