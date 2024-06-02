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
        details.push_back({b, a, c});
    }
 
    sort(details.begin(), details.end());
 
    lp(0, n)
    {
        start.push_back(get<1>(details[i]));
        end.push_back(get<0>(details[i]));
        money.push_back(get<2>(details[i]));
    }
 
    vector<int> dp(n + 1, 0);
 
    for (int i = 1; i < n + 1; i++)
    {
 
        auto it = lower_bound(end.begin(), end.begin() + i - 1, start[i - 1]) - end.begin();
 
        if (end[it - 1] > start[i - 1])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = max(dp[i - 1], money[i - 1] + dp[it]);
        }

        // auto it = upper_bound(end.begin(), end.begin() + i - 1, start[i - 1]) - end.begin() - 1;

        // if (it == -1)
        // {
        //     // No non-overlapping interval found, take current interval's money
        //     dp[i] = max(dp[i - 1], money[i - 1]);
        // }
        // else
        // {
        //     // Max of taking or not taking the current interval
        //     dp[i] = max(dp[i - 1], money[i - 1] + dp[it + 1]);
        // }
    }
 
    cout << dp[n] << endl;
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