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
    int n; cin >> n;

    vector<int> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());
    int one = arr[0];
    int two = arr[1];

    if(one == 1){
        yes;
        return;
    }

    if(two % one == 0){
        int i = 2;
        while(i < n){
            if(arr[i] % one != 0){
                two = arr[i];
                break;
            }
            i++;
        }
    }

    lp(0, n){
        if(arr[i] % one != 0 && arr[i] % two != 0){
            no;
            return;
        }
    }
    yes;
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