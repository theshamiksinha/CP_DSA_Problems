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
    int h, n; cin >> h >> n;
    vector<int> attack(n);
    vector<int> cool(n);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    lp(0, n){
        cin >> attack[i];
        pq.push({1, i});
    }

    lp(0, n){
        cin >> cool[i];
    }

    while(h > 0){

        int currAttack = pq.top().second;
        int turn = pq.top().first;

        pq.pop();

        h -= attack[currAttack];

        pq.push({turn+cool[currAttack], currAttack});

        if(h <= 0){
            cout << turn << endl;
            return;
        }

    }
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