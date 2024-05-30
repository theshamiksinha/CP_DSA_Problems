#include<bits/stdc++.h>
using namespace std;

struct Box {
    int h, w, d;
    Box(int h, int w, int d) : h(h), w(w), d(d) {}
    bool can_fit(Box& other) {
        return h < other.h && w < other.w && d < other.d;
    }
};

int bfs(vector<vector<int>>& rGraph, int s, int t, vector<int>& parent) {
    int V = rGraph.size();
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v = 0; v < V; v++) {
            if (!visited[v] && rGraph[u][v] > 0) {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
            }
        }
    }
    return visited[t];
}

int fordFulkerson(vector<vector<int>>& graph, int s, int t) {
    int V = graph.size();
    vector<vector<int>> rGraph(V, vector<int>(V));
    for (int u = 0; u < V; u++)
        for (int v = 0; v < V; v++)
            rGraph[u][v] = graph[u][v];
    vector<int> parent(V);
    int max_flow = 0;
    while (bfs(rGraph, s, t, parent)) {
        int path_flow = INT_MAX;
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
        }
        for (int v = t; v != s; v = parent[v]) {
            int u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
        }
        max_flow += path_flow;
    }
    return max_flow;
}

bool compare(Box& a, Box& b) {
    return a.h * a.w * a.d < b.h * b.w * b.d;
}

int main() {
    int n;
    cin >> n;
    vector<Box> boxes;
    for (int i = 0; i < n; i++) {
        vector<int> dimensions(3);
        cin >> dimensions[0] >> dimensions[1] >> dimensions[2];
        sort(dimensions.begin(), dimensions.end());
        boxes.push_back(Box(dimensions[0], dimensions[1], dimensions[2]));
    }
    sort(boxes.begin(), boxes.end(), compare);
    vector<vector<int>> graph(n + 2, vector<int>(n + 2, 0));
    int source = n+1;
    for (int i = 0; i < n; i++) {
        graph[source][i] = 1;
        for (int j = i + 1;j<n; j++) {
            if (boxes[i].can_fit(boxes[j])) {
                graph[i][j] = 1;
            }
            else if (boxes[j].can_fit(boxes[i])) {
                graph[j][i] = 1;
            }
        }
    }
    int sink = -1;
    int max_incoming = -1;
    for (int i = 0; i < n; i++) {
        bool outgoing = false;
        int incoming = 0;
        for (int j = 0; j < n; j++) {
            if (graph[i][j]) {
                outgoing = true;
            }
            if (graph[j][i]) {
                incoming++;
            }
        }
        if (!outgoing && incoming > max_incoming) {
            sink = i;
            max_incoming = incoming;
        }
    }
    if (sink == -1) {
        cout << "No valid sink node found." << endl;
        return 0;
    }
    // If there is a direct path from source to sink, ignore it
    if (graph[source][sink]) {
        graph[source][sink] = 0;
    }
    int ans=n-fordFulkerson(graph, source, sink);
    if(ans==0) ans+=1;
    cout << "The minimum number of visible boxes is " << ans << endl;
    return 0;
}