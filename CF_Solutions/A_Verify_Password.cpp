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
    string s; cin >>s;

    vector<char> dig;
    vector<char> let;
 
    int l = 0;
    
    lp(0, n){
        if(s[i] <= 'z' && s[i] >= 'a'){
            l = 1; 
        }
        if(!(s[i] <= 'z' && s[i] >= 'a') && l == 1){
            no;
            return; 
        }
        
    }

    lp(0, n){
        if(s[i] <= 'z' && s[i] >= 'a'){
            let.push_back(s[i]); 
        }
        if(!(s[i] <= 'z' && s[i] >= 'a')){
            dig.push_back(s[i]);
        }
        
    }
    
    if(is_sorted(dig.begin(), dig.end()) && is_sorted(let.begin(), let.end())){
        yes;
    }else{
        no;
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