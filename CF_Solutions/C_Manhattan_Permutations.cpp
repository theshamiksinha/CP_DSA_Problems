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
    int n, k; cin >> n >> k;

    if(k%2 == 1){
        no;
        return;
    }

    int max_manhattan;

    if(n%2 == 0){
        int m = n/2;
        max_manhattan = 2 * (m*(m));
    }else{
        int m = n/2;
        max_manhattan = 2 * (m*(m+1));
    }
        
    if (k > max_manhattan) {
        cout << "No" << endl;
        return;
    }
    
    cout << "Yes" << endl;
    vector<int> p(n+1);
    lp(1, n+1){
        p[i] = i;
    }
    
    for(int i = 1, j = n; i <= n;){
        int what = k - 2*(abs(p[i] - p[j])) ;

        if(what >= 0){
            swap(p[i], p[j]);
            k = what;
            i++;
            j--;
        }else{
            i++;
        }

        if(what == 0){
            break;
        }
    }

    for(int i = 1; i < n+1; i++){
        cout << p[i] << " ";
    }cout << endl;
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