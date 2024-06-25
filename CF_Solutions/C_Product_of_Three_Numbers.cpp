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
    vector<int> factors;

    for(int i = 2; i*i <= n; i++){
        if(n%i == 0 && i*i != n){
            factors.push_back(i);
            factors.push_back(n/i);
        }
        if(i*i == n){
            factors.push_back(i);
        }
    }

    if(factors.empty()){
        no;
        return;
    }
    
    map<int, int> mp;

    for(auto el : factors){
        mp[el] = 1;
    }

    for(auto el1 : factors){
        for(auto el2 : factors){
            if(n%(el1*el2) == 0 && el1 != el2){
                int target = n/(el1*el2);
                if(mp.find(target) != mp.end() && el2 != target && el1 != target){
                    int arr[] = {el1, el2, target};
                    yes;
                    print(arr);
                    return;
                }
            }
        }
    } 

    no;

    // print(factors);
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