#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define no cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define lp(a, n) for (int i = a; i < n; i++)
#define print(x)          \
    for (auto i : x)      \
    {                     \
        cout << i << " "; \
    };                    \
    cout << "\n";

#define MOD 1000000007

void solve()
{
    int n;
    cin >> n;

    int sum = n * (n + 1) / 2;

    if (sum % 2 != 0)
    {
        cout << 0 << endl;
        return;
    }

    int target = sum / 2;
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));

    dp[0][0] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= target; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= i)
            {
                dp[i][j] = (dp[i-1][j] + dp[i - 1][j - i]) % MOD;
            }
        }
    } 
    
    cout << dp[n-1][target] << endl;
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
