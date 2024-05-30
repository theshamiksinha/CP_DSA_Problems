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

vector<int> shortestPath(vector<vector<int>>& adj, int N, int src){
        
        int n = N;
        
        vector<int> dist(n, INT_MAX);
        
        queue<pair<int, int>> q;
        q.push({src, 0});
        
        dist[src] = 0;
        
        while(!q.empty()){
            
            int node = q.front().first;
            int dis = q.front().second;
            q.pop();
            
            for(auto it : adj[node]){
                
                if(dis + 1 < dist[it]){
                    dist[it] = dis + 1;
                    q.push({it, dist[it]});
                }
            }
        }
        
        for(int i = 0; i < N; i++){
            
            if(dist[i] == INT_MAX){
                dist[i] = -1;
            }
        }
        
        
        return dist;
    }

void dfsFunc(int node, vector<vector<int>> & adj, vector<int> &visited, int time){
        
    visited[node] = time;
    
    for(auto it : adj[node]){
        
        if(visited[it] == 0){
            dfsFunc(it, adj, visited, visited[node]+1);
        }else{
            visited[it] = max(time+1, visited[it]);
        }
    }
}
    
int dfsOfGraph(int V, vector<vector<int>> & adj) { 

    vector<int> visited(V+1, 0); 

    dfsFunc(1, adj, visited, 0);
    
    sort(visited.begin(), visited.end());

    return visited[V];
}

void solve(){
    
    int nodes;
    cin >> nodes;
    int st, en;
    cin >> st >> en;
    vector<vector<int>> adj(nodes + 1);

    for (int i = 0; i < nodes-1; ++i) {
        int n, m;
        cin >> n >> m;
        adj[n].push_back(m);
        adj[m].push_back(n);
 
    }

    // lp(0, nodes+1){
    //     cout << i << ": ";
    //     print(adj[i]);
    // }

    // cout << endl;

    // cout<< 32222 << endl;

    vector<int> dist = shortestPath(adj, nodes+1, st);

    cout << dist[en] << endl; 

    int time = dfsOfGraph(nodes, adj);

    cout << time << endl;cout << endl;




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