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
    int n, k, pb, ps; cin >> n >> k >> pb >> ps;
    vector<int> p(n), a(n);

    lp(0, n){
        cin >> p[i];
    }
    lp(0, n){
        cin >> a[i];
    } 

    vector<int> vis(n, 0);
    vector<int> pathB;
    int i = pb-1;
    while(vis[i] != 1){
        vis[i] = 1;
        pathB.push_back(a[i]);
        i = p[i]-1;
    }

    vis = vector<int>(n, 0);
    vector<int> pathS;
    i = ps-1;
    while(vis[i]!=1){
        vis[i] = 1;
        pathS.push_back(a[i]);
        i = p[i]-1;
    }

    int ansB = INT_MIN;
    int preSum=0; 
    for(i = 0; i < pathB.size(); i++){
        if(k < i+1){
            break;
        }
        int temp = preSum + (k-i)*pathB[i]; 
        preSum += pathB[i];
        ansB = max(ansB, temp); 
    }  

    int ansS = INT_MIN;
    preSum=0; 
    for(i = 0; i < pathS.size(); i++){
        if(k < i+1){
            break;
        }
        int temp = preSum + (k-i)*pathS[i]; 
        preSum += pathS[i];
        ansS = max(ansS, temp); 
    }  

    if(ansB > ansS){
        cout << "Bodya" << endl;
    }else if(ansB == ansS){
        cout << "Draw" << endl;
    }else{
        cout << "Sasha" << endl;
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