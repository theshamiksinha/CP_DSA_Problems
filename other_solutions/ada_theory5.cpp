#include<bits/stdc++.h>
using namespace std;


bool compare(const vector<int> &a, const vector<int> &b) {
    return tie(a[0], a[1], a[2]) < tie(b[0], b[1], b[2]);
}

bool can_fit(const vector<int> & a, const vector<int> & b) {
    return a[0] < b[0] && a[1] < b[1] && a[2] < b[2];
}

int bfs(vector<vector<int>>& residualAdj, int s, int t, vector<int>& parent) {

    int V = residualAdj.size();
    vector<bool> visited(V, false);

    queue<int> q;
    q.push(s);

    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && residualAdj[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(vector<vector<int>>& adjMat, int s, int t) {

    int V = adjMat.size();

    vector<vector<int>> residualAdj(V, vector<int>(V));
    
    residualAdj = adjMat; 
        
    vector<int> parent(V);

    int maxFlow = 0;
    while (bfs(residualAdj, s, t, parent)) {
        int pathFlow = INT_MAX;

        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
           pathFlow = min(pathFlow, residualAdj[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            residualAdj[u][v] -=pathFlow;
            residualAdj[v][u] +=pathFlow;
        }
        maxFlow +=pathFlow;
    }
    return maxFlow;
}

int main() {
    int n; cin >> n;
    
    vector<vector<int>> boxes(n, vector<int>(3));
    for (int i = 0; i < n; i++) { 

        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];

        sort(boxes[i].begin(), boxes[i].end());
    }

    vector<vector<int>> adjMat(2*n + 2, vector<int>(2*n + 2));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++) {
            if (can_fit(boxes[i], boxes[j]) && i != j) {
                adjMat[i+1][n+j+1] = 1;
            }
        }
    }

    for (int i = 1; i <= n; ++i){
        adjMat[0][i] = 1;
        adjMat[i + n][(2 * n) + 1] = 1;
    } 
 
    int ans = n - fordFulkerson(adjMat, 0, 2*n+1);
    if (ans == 0) ans += 1;
    cout << "Minimum number of visible boxes is " << ans << endl;
    return 0;
}


 