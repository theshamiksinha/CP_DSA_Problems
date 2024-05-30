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
#define print(x) for(auto i: x) { cout << i << ""; };


void solve(){
    int n, m, k; cin >> n >> m >> k;

    if(k%2 == 1){
        cout << "IMPOSSIBLE" << endl;
        return;
    }

    vector<string> maze(n);
    vector<vector<int>> dist(n, vector<int>(m, 1e10));

    int x, y;

    for(int i = 0; i < n; i++) {
        cin >> maze[i];
        for(int j = 0; j < m; j++){
            if(maze[i][j] == 'X'){
                x = i;
                y = j;
            }
        }
    } 

    vector<char> moves = {'D', 'L', 'R', 'U'};
    vector<int> delX = {1, 0, 0, -1};   
    vector<int> delY = {0, -1, 1, 0};

    queue<pair<int, int> > q; 

    vector<char> ans;

    q.push({x, y});  
    dist[x][y] = 0;
 
    while(!q.empty()){ 
        int x_coord = q.front().first;
        int y_coord = q.front().second;
        
        q.pop();

        for(int i = 0; i < 4; i++){
            int newX = x_coord + delX[i];
            int newY = y_coord + delY[i];
 
            if(newX < n && newX >= 0 
            && newY >= 0 && newY < m 
            && (maze[newX][newY] != '*')
            && dist[newX][newY] == 1e10){

                q.push({newX, newY}); 
                dist[newX][newY] = dist[x_coord][y_coord] + 1;
            } 
        }
    } 
    
    while(k--){ 
        int check = 0;
        for(int i = 0; i < 4; i++){
            int newX = x + delX[i];
            int newY = y + delY[i];
 
            if(newX < n && newX >= 0 
            && newY >= 0 && newY < m 
            && (maze[newX][newY] != '*')
            && dist[newX][newY] <= k){
  
                ans.push_back(moves[i]);

                x = newX;
                y = newY;

                check = 1;

                break;
            }
        }
        if(check == 0){
            cout << "IMPOSSIBLE" << endl;
            return;
        }
    }
 
    print(ans);
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