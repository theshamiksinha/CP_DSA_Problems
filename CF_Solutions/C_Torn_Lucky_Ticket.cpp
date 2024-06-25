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
    vector<string> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    vector<vector<int>> cnt(6, vector<int>(46, 0));

    for(auto it : arr){
        int sum = 0;
        int size = it.size();
        for (char c : it) {
            sum += c - '0';
        }
        cnt[size][sum]++;
    }

    int ans = 0;
    for(auto it : arr){
        int size = it.size();
        vector<int> pref(size+1, 0);
        for(int i = 1; i <= size; i++){
            pref[i] = pref[i-1] + (it[i-1]-'0');
        } 
        
        for (int lenr = size % 2; lenr <= size; lenr += 2) {
            int l = size + lenr;
            int suml = pref[l / 2];
            int sumr = pref[size] - suml;
            int diff = suml - sumr;

            if (diff >= 0 && diff <= 45) {
                ans += cnt[lenr][diff];
            }
        }

        for (int lenl = size % 2; lenl < size; lenl += 2) {
            int l = size + lenl;
            int suml = pref[size] - pref[size - l / 2];
            int sumr = pref[size - l / 2];
            int diff = suml - sumr;

            if (diff >= 0 && diff <= 45) {
                ans += cnt[lenl][diff];
            }
        }
    }

    cout << ans << endl;
 
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int x = 1;
    // cin >> x;
    while(x--){
        solve();
    }
}