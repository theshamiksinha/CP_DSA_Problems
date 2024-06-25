#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define lpp(a,n)  for(int j =a; j< n; j++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    
    if (n == 2) {
        if (s[0] == '0') {
            cout << s[1] << endl;
            return;
        }
        cout << s << endl;
        return;
    }
    
    int check = 0;
    lp(0, s.size()){
        if (s[i] == '0') {
            check = 1;
        }
    }
    
    int sol = INT_MAX;
    
    if (check) {
        if (n >= 4) {
            cout << 0 << endl;
        } 
        else {
            if (s[1] == '0') { 
                int sol = min((s[0] - '0')+(s[2] - '0'), (s[0] - '0')*(s[2] - '0'));
                cout << sol << endl;
            } else {
                cout << 0 << endl;
            }
        }
        return;
    }
    
    lp(0, n-1) {
        vector<int> ar;
        lpp(0, n){
            string val = "";
            if (j == i) { 
                val = val + s[j] + s[j + 1];
                j++;
                ar.push_back(stoi(val));
            } else {
                val = val + s[j];
                ar.push_back(stoi(val));
            }
        }
        
        int temp = ar[0];
        if (temp == 1) {
            temp = 0;
        }
        
        lp(1, ar.size()) {
            if (ar[i] == 1) {
                continue;
            }
            temp = temp + ar[i];
        }
        
        sol = min(sol, temp);
    }
    
    cout << sol << endl;
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