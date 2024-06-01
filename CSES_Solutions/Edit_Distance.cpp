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

#define MOD 1000000007;

void solve()
{
    string a, b;
    cin >> a >> b;

    int s1 = a.size();
    int s2 = b.size();

    vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1, 0));
    for (int i = 0; i <= s1; i++)
    {
        dp[i][0] = i;
    }
    for (int i = 0; i <= s2; i++)
    {
        dp[0][i] = i;
    }

    // dp[i][j] -> no. of operations required to convert string of length i to a string of length j
    // 1. add a char ->>> dp[i][j-1] + 1
    // 2. remove a char ->>> dp[i-1][j] + 1
    // 3. replace a char ->>> dp[i-1][j-1] + 1

    for (int i = 1; i < s1 + 1; i++)
    {
        for (int j = 1; j < s2 + 1; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
            }
        }
    }

    cout << dp[s1][s2] << endl;
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