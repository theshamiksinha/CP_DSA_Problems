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
    int x, y; cin >> x>>y;

    if(y%2 == 0){
        int sec = ceil(y/2.0);

        int one = x - sec*7;

        if(one > 0){
            int plus = ceil(one/15.0);
            cout << sec+plus << endl;
        }else{
            cout <<  sec << endl;
        }
    }else{

        int sec = ceil((y-1)/2.0);

        int one = x - sec*7 - 11;

        if(one > 0){
            int plus = ceil(one/15.0);
            cout << sec+plus+1 << endl;
        }else{
            cout << sec+1 << endl;
        }
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