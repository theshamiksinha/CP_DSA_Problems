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

    if(is_sorted(arr.begin(), arr.end())){
        yes;
        return;
    }

    int part = 1;

    for(int i = 1; i < n; i++){
        if(arr[i] >= arr[i-1]){
            continue;
        }else{
            part++;
        }
    } 

    map<int, int> cnt;

    int pt = 0;
    int old = 0;

    while(pt < n){
        auto it = cnt.find(arr[pt]);
        if(old <= arr[pt]){
            if(it == cnt.end()){
                cnt[arr[pt]] = 1; 
            }
            old = arr[pt];
        }else{  
            break;
        }
        pt++;
    }   

    int was = pt;

    vector<int> check1;
    vector<int> check2;

    int pt2 = 0;
    while(pt2 < pt){
        check1.push_back(arr[pt2]);
        pt2++;
    }
    while(pt < n){
        check1.push_back(arr[pt]);
        pt++;
    } 

    pt2 = 0;
    pt = was;
    while(pt < n){
        check2.push_back(arr[pt]);
        pt++;
    } 
    pt = was;
    while(pt2 < pt){
        check2.push_back(arr[pt2]);
        pt2++;
    }

    if(is_sorted(check1.begin(), check1.end()) || is_sorted(check2.begin(), check2.end())){
        
        yes;
    }else{ 
        no;
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