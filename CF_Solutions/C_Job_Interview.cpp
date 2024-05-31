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
    int n, m; cin >> n >> m;
    int a = n, b = m;
    vector<int> pro(n+m+1), tes(n+m+1);

    lp(0, n+m+1){
        cin >> pro[i];
    }

    lp(0, n+m+1){
        cin >> tes[i];
    }

    vector<int> nPros, mTests;

    int total = 0;

    int x = -1; 

    lp(0, m+n+1){
        if(pro[i] > tes[i] && a != 0){
            nPros.push_back(i);
            total += pro[i];
            a--; 
        }
        else if(pro[i] > tes[i] && a == 0){
            x = i; 
            break;
        }
        else if(pro[i] < tes[i] && b != 0){
            mTests.push_back(i);
            total += tes[i];
            b--;
        }
        else if(pro[i] < tes[i] && b == 0){
            x = i; 
            break;
        }
    }

    if(nPros.size() == n){
        lp(x+1, m+n+1){
            mTests.push_back(i);
            total += tes[i];
        } 
    }else if(mTests.size() == m){
        lp(x+1, m+n+1){
            nPros.push_back(i);
            total += pro[i];
        } 
    }
    
    vector<int> ans(n+m+1); 

    lp(0, n+m+1){

        auto inN = lower_bound(nPros.begin(), nPros.end(), i);
        auto inM = lower_bound(mTests.begin(), mTests.end(), i);
        if(inN != nPros.end() && *inN == i) { 
            int temp = total - pro[i] + pro[x]; 
            ans[i] = temp;
            continue;
        }
        if(inM != mTests.end() && *inM == i) {
            int temp = total - tes[i] + tes[x]; 
            ans[i] = temp;
            continue;
        }
        ans[i] = total;
    }

    print(ans);
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