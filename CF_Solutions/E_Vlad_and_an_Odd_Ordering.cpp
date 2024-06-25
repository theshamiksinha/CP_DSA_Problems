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
    int n, k; cin >> n >> k;

    vector<int> row;
    
    int tempN = n;
    while(tempN != 0){
        row.push_back(ceil(tempN/2.0));
        tempN = tempN - ceil(tempN/2.0);
    }
    
    vector<int> pref(row.size()+1, 0);
    lp(1, row.size()+1){
        pref[i] = pref[i-1] + row[i-1]; 
    }  

    int pos = upper_bound(pref.begin(), pref.end(), k) - pref.begin();

    if(pref[pos - 1] == k){
        cout << (int)(pow(2, pos-2)*(2*(pref[pos-1]-pref[pos-2]-1)+1)) << endl;
 
    } else{

        cout << (int)(pow(2, pos-1)*(2*(k-pref[pos-1]-1)+1)) << endl;
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