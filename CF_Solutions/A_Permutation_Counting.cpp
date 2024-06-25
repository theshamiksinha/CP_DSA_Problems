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


bool possible(int mid, vector<int> &pref, int k, int n, vector<int> &searchable){

    int needed = mid*searchable[mid] - pref[mid];
    if(needed > k){
        return false;
    }else{
        return true;
    }
}
 

void solve(){
    int n, k; cin >> n >> k;
    vector<int>a(n);

    for(int x=0;x<n;x++){
        cin>>a[x];
    }

    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());

    int lst=a.back(),cnt=1; 
    a.pop_back();

    while(!a.empty()&&lst==a.back()){ 
        a.pop_back(),cnt++;
    } 
    
    while(!a.empty())
    {
        int delta=a.back()-lst;
        if(k < delta*cnt){
            break;
        }
        k -= delta*cnt;
        lst=a.back();
        while(!a.empty() && lst==a.back()){ 
            a.pop_back(),cnt++;
        }
    }

    lst += k/cnt;
    k %= cnt;
    cnt -= k;
    cout<<lst*n-cnt+1<<endl;
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