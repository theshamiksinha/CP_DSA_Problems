#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;

#define int long long
#define no  cout << "NO" << endl;
#define yes cout << "YES" << endl;
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";

#define MOD 1000000007;

void solve(){
    int n; cin >> n;
    vector<int> arr(n);
    int one = 0;
    lp(0, n){
        cin >> arr[i];
        if(arr[i] == 1){
            one++;
        }
    }

    if(one == n){
        yes;
        return;
    }

    if(one == 0){
        no;
        return;
    } 

    set <int> facs;

    for(int i = 2; i*i < n; i++){
        if(n%i == 0 && i*i != n){
            facs.insert(n/i);
            facs.insert(i);
        }
        if(i*i == n){
            facs.insert(i);
        }
    }

    arr.push_back(arr[0]);
    map<int, int> mp;
    lp(0, n+1){
        if(arr[i] == 1){
            mp[i]++;
        }
    }

    for(auto it : facs){ 
        
        for(auto inmap : mp){
            int check = 1;
            int sides = 1;
            int pos = inmap.first;
            int last = -1;
            int nextAt = pos+it;
            while(nextAt < n+1){
                if(mp.find(nextAt) != mp.end()){
                    sides++;
                    last = nextAt;
                    nextAt += it;
                }else{
                    check = 0;
                    break;
                } 
            }   
            if(check){

                if(sides <= 2){
                    
                    continue;
                }    
                if(pos == 0 && last == n){ 
                    if(sides-1 <= 2){
                        continue;
                    }   
                    yes;
                    return;
                } 
                if( (n-1-last) + (pos) != it-1){
                    continue;
                } 
                yes;
                return;
            }
        }
    }

    no;
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