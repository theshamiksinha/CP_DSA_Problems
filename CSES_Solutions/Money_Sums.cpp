#pragma GCC optimize("O3,unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define no cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a) * (b) / gcd(a, b))
#define lp(a, n) for (int i = a; i < n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

void solve()
{
    int n;
    cin >> n;

    vector<int> coins(n);
    int sum = 0;
    lp(0, n)
    {
        cin >> coins[i];
        sum += coins[i];
    }

    vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][0] = 1;
    }

    // dp[i][j] = dp[i-1][j] + dp[i-1][j-coins[i-1]]
    // dp[i][j] = can i create a sum of j using the coins array from 0 to ith index?

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (j >= coins[i - 1])
            {
                dp[i][j] = dp[i - 1][j] + dp[i - 1][j - coins[i - 1]];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    vector<int> ans;

    int count = 0;

    for (int i = 1; i < sum + 1; i++)
    {
        if (dp[n][i] != 0)
        {
            count++;
            ans.push_back(i);
        }
    }

    cout << count << endl;
    print(ans);
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