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

class DisjointSet{
    
public:
    vector<int> rank, parent, size;

    DisjointSet(int n){
        rank.resize(n+1, 0);
        size.resize(n+1, 0);
        parent.resize(n+1);

        for(int i = 0; i < n+1; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findParent(int node){
        if(node == parent[node]){
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v){

        int ultimateU = findParent(u);
        int ultimateV = findParent(v);

        if(ultimateU == ultimateV){
            return;
        }

        if(rank[ultimateU] < rank[ultimateV]){
            parent[ultimateU] = ultimateV;
        }else if(rank[ultimateU] > rank[ultimateV]){
            parent[ultimateV] = ultimateU;
        }else{
            parent[ultimateV] = ultimateU;
            rank[ultimateU]++;
        }
    }

    void unionBySize(int u, int v){

        int ultimateU = findParent(u);
        int ultimateV = findParent(v);

        if(ultimateU == ultimateV){
            return;
        }

        if(size[ultimateU] < size[ultimateV]){
            parent[ultimateU] = ultimateV;
            size[ultimateV] += size[ultimateU];
        }else{
            parent[ultimateV] = ultimateU;
            size[ultimateU] += size[ultimateV];
        }
    }

};

bool isValid(int r, int c, int n, int m){

    if(r < n && r >= 0 && c >= 0 && c < m){
        return true;
    }
    return false;
}

void solve(){
    int n, m; cin >> n >> m;
    vector<string> grid(n);
    lp(0, n){
        cin >> grid[i];
    }

    DisjointSet ds(n*m);
    int ans = 0;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(grid[row][col] == '.'){
                continue;
            } 

            int newr[] = {1, 0, -1, 0};
            int newc[] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++){
                int nr = newr[k]+row;
                int nc = newc[k]+col;

                if(isValid(nr, nc, n, m) && grid[nr][nc] == '#'){
                    int node = row*m + col;
                    int other = nr*m + nc;
                    ds.unionBySize(node, other);
                }
            }
            
        }
    }

    for(int row = 0; row < n; row++){
        set<int> comp;
        int plus = 0;
        for(int col = 0; col < m; col++){ 
            if(grid[row][col] == '.'){
                plus++;
            }
            int newr[] = {1, 0, -1, 0};
            int newc[] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++){
                int nr = newr[k]+row;
                int nc = newc[k]+col;

                if(isValid(nr, nc, n, m) && grid[nr][nc] == '#'){ 
                    int other = nr*m + nc;
                    int par = ds.findParent(other);
                    comp.insert(par);
                }
            }
        }
        int size = 0;
        for(auto it : comp){
            size += ds.size[it];
        }
        ans = max(ans, size+plus); //1 for the connecting node between other nodes
    }


    for(int col = 0; col < m; col++){ 
        set<int> comp;
        int plus = 0;
        for(int row = 0; row < n; row++){
            if(grid[row][col] == '.'){
                plus++;
            }
            int newr[] = {1, 0, -1, 0};
            int newc[] = {0, 1, 0, -1};

            for(int k = 0; k < 4; k++){
                int nr = newr[k]+row;
                int nc = newc[k]+col;

                if(isValid(nr, nc, n, m) && grid[nr][nc] == '#'){ 
                    int other = nr*m + nc;
                    int par = ds.findParent(other);
                    comp.insert(par);
                }
            }
        }
        int size = 0;
        for(auto it : comp){
            size += ds.size[it];
        }
        ans = max(ans, size+plus); //1 for the connecting node between other nodes
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(grid[i][j] == '#'){
                int node = i*m + j;
                int UltimateNode = ds.findParent(node);
                int size = ds.size[UltimateNode];
                ans = max(size, ans);
                continue;
            }
        }
    }

    cout << ans << endl;
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