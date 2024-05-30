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

    vector<int> arr(n);

    lp(0, n){
        cin >>arr[i];
    }

    map<pair<int, int>, set<int>> m, m2, m3;

    int lo = 0, hi = 2;
    vector<vector<int>> comb;

    while(hi < n){
        vector<int> triple;
        triple.push_back(arr[lo]);
        triple.push_back(arr[lo+1]);
        triple.push_back(arr[hi]);

        comb.push_back(triple);

        lo++; hi++;
    }

    int size = comb.size();

    lp(0, size){
        m[{comb[i][0], comb[i][1]}].insert(comb[i][2]);
        m2[{comb[i][0], comb[i][2]}].insert(comb[i][1]);
        m3[{comb[i][1], comb[i][2]}].insert(comb[i][0]);
    } 

    int count = 0;
    for(auto it : m){

        int s = it.second.size();
        count += s*(s-1)/2;
        // if(it.second.size() != 1){
            // cout << it.first.first << " " << it.first.second <<" X :";
            // print(it.second);
        // }
    }
    // cout <<  endl;
    for(auto it : m2){
        int s = it.second.size();
        count += s*(s-1)/2;
        // if(it.second.size() != 1){
            // cout << it.first.first << " X " << it.first.second <<" :";
            // print(it.second);
        // }
    }
    // cout << endl;
    for(auto it : m3){
        int s = it.second.size();
        count += s*(s-1)/2;
        // if(it.second.size() != 1){
            // cout << "X " << it.first.first << " " << it.first.second <<" :";
            // print(it.second);
        // }
    }

    // cout << endl;
    // cout << "...." << endl;

    cout<< count << endl; 
    // cout << "...." << endl;

    
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