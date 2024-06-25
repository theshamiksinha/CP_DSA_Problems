#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std; 

void solve(){
    int a, b, c; cin >> a>> b>> c;
     

    int ans1= abs(a-a) + abs(b-a) + abs(c-a);
    int ans2= abs(a-b) + abs(b-b) + abs(c-b);
    int ans3= abs(a-c) + abs(b-c) + abs(c-c);

    cout << min(ans1, min(ans2, ans3)) << endl;
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