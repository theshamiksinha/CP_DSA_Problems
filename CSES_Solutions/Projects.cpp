#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;
 
#define int long long 
#define lp(a, n) for (int i = a; i < n; i++) 
 
void solve()
{
    int n;
    cin >> n;
 
    vector<int> start, end, money;
    vector<tuple<int, int, int>> details;
 
    lp(0, n)
    {
        int a, b, c;
        cin >> a >> b >> c;
        details.push_back({a, b, c});
    }
 
    sort(details.begin(), details.end());
 
    lp(0, n)
    {
        start.push_back(get<0>(details[i]));
        end.push_back(get<1>(details[i]));
        money.push_back(get<2>(details[i]));
    }
 
    vector<int> dp(n + 1, 0); 

    for (int i = n - 1; i >= 0; i--)
    {
        auto it = upper_bound(start.begin() + i + 1, start.end(), end[i]) - start.begin();
        if (it >= n)
        {
            dp[i] = max(dp[i + 1], money[i]);
        }
        else
        {
            dp[i] = max(dp[i + 1], money[i] + dp[it]);
        }
    }

    cout << dp[0] << endl;
 
}
 
signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    // cin >> x;
    while (x--)
    {
        solve();
    }
}