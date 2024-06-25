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
    int n, c; cin >> n >> c;
    vector<int> arr(n);
    int maxi = INT_MIN;
    int maxiIND = -1;
    lp(0, n){
        cin >> arr[i];
        if(i == 0){
            arr[i] += c;
        }
        if(arr[i] > maxi){
            maxi = arr[i];
            maxiIND = i;
        }
    }
    int presum = 0;
    for(int i = 0; i < n; i++){

        if(arr[i] >= maxi && arr[i] == maxi){

            if(i == 0 || i == maxiIND){
                cout << 0 << " ";
            }else{
                cout << i << " ";
            }

        }else if(arr[i] >= maxi){
            cout << 0 << " ";
        }else{
            if(arr[i]+presum >= maxi){
                cout << i << " ";
            }else{
                cout << i + 1 << " ";
            }
        }

        presum += arr[i];
    }
    cout << endl;
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