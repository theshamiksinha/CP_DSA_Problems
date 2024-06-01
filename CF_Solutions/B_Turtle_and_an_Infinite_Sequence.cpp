#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;

void solve(){
    int n, m;
    cin >> n >> m;

    if(m == 0){
        cout << n << endl;
        return;
    }

    // Find the leftmost set bit position
    int msb_pos = 63 - __builtin_clzll(n + m);

    // Find the rightmost set bit position
    int lsb_pos = 63 - __builtin_clzll(max(n - m, 1LL));

    int ans = ((1LL << (msb_pos + 1)) - 1) ^ ((1LL << lsb_pos) - 1);

    msb_pos = __builtin_ctzll(m+n);

    // Find the rightmost set bit position
    lsb_pos = __builtin_ctzll(max(n - m, 1LL));

    // Compute the result by setting bits from lsb_pos to msb_pos
    int temp = ((1LL << (msb_pos + 1)) - 1) ^ ((1LL << lsb_pos) - 1);

    cout << (ans|temp|(m+n)|(1)|(max(n-m, 1LL)|n)) << endl;
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
