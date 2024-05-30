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


struct node{
    int sum;
};

node merge(node a, node b){
    node ans;
    ans.sum = a.sum + b.sum;
    return ans;
}

node t[4*200200];

node build(int id, int l, int r){
    if(l==r){
        t[id].sum = 0;
        return;
    }

    int mid = (l+r)/2;
    build(2*id, l, mid);
    build(2*id+1, mid+1, r);

    t[id] = merge(t[2*id], t[2*id+1]);
}

void update(int id, int l, int r, int pos, int val){

    if(pos < l || pos > r){
        return;
    }
    if(l == r){
        
    }

}

void query(int id, int l, int r, int lq, int rq){

}

void solve(){
    

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