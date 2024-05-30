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
    int n, k; cin >> n >> k;

    k--;

    vector<int> arr(n);
    lp(0, n){
        cin >> arr[i];
    }

    int maxi1 = 0;
    swap(arr[0], arr[k]);
    int toCheck = arr[0];
    int i = 0;
    int winner = INT_MIN;
    while(toCheck == arr[0] && i <= n-2){
        winner = max(winner, max(arr[i], arr[i+1]));
        if(winner == toCheck){ 
            maxi1++;
        }else{ 
            break;
        }
        i++; 
    } 
    swap(arr[0], arr[k]);

    int toSwap = 0;
    lp(0, k){
        if(arr[i] > arr[k]){
            toSwap = i;
            break;
        }
    }

    

    int maxi2 = 0;
    swap(arr[toSwap], arr[k]);
    toCheck = arr[toSwap];
    i = 0; 
    winner = INT_MIN;
    while(toCheck == arr[toSwap] && i <= n-2){
        winner = max(winner, max(arr[i], arr[i+1]));
        if(winner == toCheck){
            maxi2++;
        }
        i++;
    }

    cout << max(maxi1, maxi2) << endl;

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