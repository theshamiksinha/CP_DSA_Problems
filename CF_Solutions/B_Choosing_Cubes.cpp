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
    int n, f, k; cin >> n >> f >>k; f--; k--;
    vector<int> arr(n, 0);
    lp(0, n){
        cin >> arr[i];
    }

    int fav = arr[f];

    sort(arr.begin(), arr.end(), greater<int>());

    if(k+1 >= n ){
        yes;
        return;
    } 

    if(arr[k] < fav){
        yes;
        return;
    }

    if(arr[k] > fav){
        no;
        return;
    }

    if(arr[k] == fav && arr[k+1] == fav){
        cout << "maybe" << endl;
        return;
    }else if(arr[k] == fav && arr[k+1] != fav){
        yes;
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