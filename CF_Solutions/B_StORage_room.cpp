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
    vector<vector<int>> M(n, vector<int>(n));

    vector<int> a (n, (1<<30)-1);

    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            cin >> M[i][j];
            if(i != j){
                a[i] &= M[i][j];
                a[j] &= M[i][j];
            }
        }
    } 

    bool ok = true;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++){
            if(i != j && (a[i] | a[j]) != M[i][j]){
                no;
                return; 
            }
        }
    }
    yes;
    print(a); 
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