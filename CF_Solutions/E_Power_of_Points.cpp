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
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> ar;
    for(int i = 0; i < n; i++) {
        cin >> arr[i].first;
        arr[i].second = i;
        ar.push_back(arr[i].first);
    }

    sort(arr.begin(), arr.end());
    sort(ar.begin(), ar.end());

    vector<int> pref(n+1, 0);

    for(int i = 1; i < n+1; i++) {
        pref[i] = pref[i-1] + arr[i-1].first;
    } 

    vector<int> ans(n);

    for(auto el : arr){

        int it = el.first;
        int where = el.second;

        int pos = lower_bound(ar.begin(), ar.end(), it) - ar.begin();

        int aage = pref[n] - pref[pos];
        aage -= (n-pos)*it;
        aage += (n-pos);

        int peeche = pref[pos];
        peeche = pos*it - peeche + pos;

        ans[where] = (aage + peeche);
    }

    print(ans);
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