#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";


void solve(){
    int n, m, x; cin >> n >> m >> x;
    vector<int> way1;
    vector<char> way2;
    lp(0, m){
        int a; char c; cin >> a >> c;
        way1.push_back(a);
        way2.push_back(c);
    } 

    set<int> q;
    q.insert(x); 

    for(int i = 0; i < m; i++){
        int dis = way1[i];
        int dir = way2[i];

        set<int> temp;

        for(auto first : q){ 

            if(dir == '0' || dir == '?'){  
                int ok2 = (first + dis)%n; 
                temp.insert(ok2);
            }

            if(dir == '1' || dir == '?'){
                int ok1 = (first - dis)%(n); 
                temp.insert(ok1);
            }
        }
        q = temp;
    }

    cout << q.size() << endl;
    print(q);
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