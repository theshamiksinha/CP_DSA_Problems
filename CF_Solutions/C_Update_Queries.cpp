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
    int n, m;
    cin >> n >> m;
    string s, c;
    cin >> s;
    set<int> st;
    lp(0, m)
    {
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    cin >> c;
    sort(c.begin(), c.end());

    int j = 0;
    for (auto i : st)
    {
        int ind = i - 1;
        s[ind] = c[j++];
    }
    cout << s << endl;
}

signed main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    cin >> x;
    while (x--)
    {
        solve();
    }
}