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
bool good(vector<int>&b){
    int g = __gcd(b[0], b[1]);
    for(int i = 1; i <  (b.size()) - 1; i++){
        int cur_gcd = __gcd(b[i], b[i + 1]);
        if(g > cur_gcd) return false;
        g = cur_gcd;
    }
    return true;
}

void solve(){
    int n; cin >> n;
    vector<int> a (n);

    lp(0, n){
        cin >> a [i];
    }

    int g = -1;
    int to_del = -1;
    for(int i = 0; i < n - 1; i++){
        int cur_gcd = __gcd(a[i], a[i + 1]);
        if(cur_gcd < g){
            to_del = i;
            break;
        }
        g = cur_gcd;
    }
    if(to_del == -1) {yes; return;}
    vector<int>b0 = a, b1 = a, b2 = a;
    if(to_del > 0) b0.erase(b0.begin() + to_del - 1);
    b1.erase(b1.begin() + to_del);
    if(to_del < n - 1) b2.erase(b2.begin() + to_del + 1);
    if (good(b0) || good(b1) || good(b2)){
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