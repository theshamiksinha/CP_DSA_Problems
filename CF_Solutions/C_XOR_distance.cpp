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
    int a, b, r; cin >> a >> b >>r;
    if(a > b){
        swap(a, b);
    }
    int x = 0;
    int cnt = 0;
    int sum = 0;

    for(int i = 63; i >= 0; i--){
        int bit1 = (a >> i) & 1;
        int bit2 = (b >> i) & 1;
        if(bit1 == bit2 || (bit1 == 1 && bit2 == 0)){ 
        }else{
            if(cnt == 0){ 
                cnt++;
            }else{
                int temp = x;
                x = x | (1ll<<i);
                if(x > r){
                    x = temp; 
                }  
            }
        }
    }  
    cout << abs((a^x) - (b^x)) << endl;  
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