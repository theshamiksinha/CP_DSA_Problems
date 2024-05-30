#pragma GCC optimize("O3,unroll-loops")
#include<bits/stdc++.h>
using namespace std;
#define no  cout << "No" << endl;
#define yes cout << "Yes" << endl;
#define int long long
#define gcd(a, b) __gcd(a, b)
#define lcm(a, b) ((a)*(b)/gcd(a, b))
#define lp(a,n)  for(int i =a; i< n; i++)
#define print(x) for(auto i: x) { cout << i << " "; }; cout << "\n";


void dfs(int node, vector<int> &visited, vector<vector<int>> & adj, vector<int> &ans){

    visited[node] = 1;
    ans.push_back(node); 
    
    for(auto it : adj[node]){
        if(!visited[it]){
            dfs(it, visited, adj, ans);
        }
    }
}


void solve(){
    int n, m; cin >> n >> m;
    vector<vector<int>> edges;
    vector<vector<int>> adj(n);
    lp(0, m){
        int a, b, x; cin >> a>> b>> x;
        adj[a-1].push_back(b-1);
        edges.push_back({a-1, b-1, -x});        
    }

    vector<int> dist(n, LLONG_MAX);

    dist[0] = 0;

    for (int i = 0; i < n-1; i++)
    {
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
                dist[v] = dist[u] + wt;
            }
        }
    } 

    for(auto it : edges){
        int u = it[0];
        int v = it[1];
        int wt = it[2];
 
        if(dist[u] != LLONG_MAX && dist[u] + wt < dist[v]){
            vector<int> ans;
            vector<int> visited1(n, 0);
            dfs(u, visited1, adj, ans);

            for (int i = 0; i < ans.size(); i++)
            {
                if(ans[i] == n-1){
                    cout << -1 << endl;
                    return;
                }
            }   
        }
    }
    
    cout << -dist[n-1] << endl;
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