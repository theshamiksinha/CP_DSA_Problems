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
    int n; cin >> n;
    int min1 = INT_MAX;
    int min2 = INT_MAX;

    int oth = INT_MAX;

    while(n--){
        int a; cin >> a;
        string s; cin >> s;
        if(s == "01"){
            min1 = min(min1, a);
        }
        if(s == "10"){
            min2 = min(min2, a);
        } 
        if(s == "11"){
            oth = min(oth, a);
        }  
    }

    if((min1 == INT_MAX || min2 == INT_MAX) && oth == INT_MAX){
        cout << -1 << endl;
    }else{
        cout << min( min1 + min2, oth)<< endl;
    }
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