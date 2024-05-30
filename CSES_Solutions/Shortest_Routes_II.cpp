#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";
 
 
void solve(){
    int n, m, q; cin >> n >> m >> q;
    vector<vector<int>> adjMat(n, vector<int>(n, LONG_LONG_MAX)); 
    lp(0, m){
        int st, en, wt; cin >> st >> en >> wt;
        st--;
        en--;
        adjMat[st][en] = min(adjMat[st][en], wt);
        adjMat[en][st] = min(adjMat[st][en], wt);
    }
 
    for(int k = 0; k < n; k++){
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if(adjMat[i][k] < LONG_LONG_MAX && adjMat[k][j] < LONG_LONG_MAX){
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                } 
            }
        }
    }
 
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if(adjMat[i][j] == LONG_LONG_MAX){
                adjMat[i][j] = -1; 
            }
        }
    }
 
    lp(0, q){
        int st, en;cin >> st >> en; 
        st--; en--;
        if(st == en){
            cout << 0 << endl;
            continue;
        }
        cout << adjMat[st][en] << endl;
    }
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