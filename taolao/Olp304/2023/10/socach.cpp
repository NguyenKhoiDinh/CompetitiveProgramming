#include <bits/stdc++.h>
using namespace std; 
const int mod = 1000000000; 
int dx[4] = {-1, 1, 2, 2}; 
int dy[4] = {2, 2, 1, -1}; 
int n, m, k, q; 
stack <int> store; 
vector <int> topo; 
int dp[1000005]; 
bool blocked[1005][1005]; 
vector <int> adj[1000005]; 

int calc(int x, int y) {
  return m * x + y; 
}

pair <int, int> convertToCoordinate(int value) {
  return make_pair(value / m, value % m); 
}

void dfs(int u) {
  pair <int, int> currentCoordinate = convertToCoordinate(u); 
  blocked[currentCoordinate.first][currentCoordinate.second] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    pair <int, int> coor = convertToCoordinate(v); 
    if (blocked[coor.first][coor.second] == false) {
      dfs(v); 
    }
  }
  store.push(u); 
}

int main () {
  freopen("SOCACH.INP", "r", stdin);
  freopen("SOCACH.OUT", "w", stdout);
  cin >> n >> m >> k >> q;
  for (int i = 1; i <= k; i++) {
    int x, y;
    cin >> x >> y;
    blocked[x - 1][y - 1] = true; 
  } 
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (blocked[x][y] == true) {
        continue; 
      }
      for (int t = 0; t < 4; t++) {
        int xx = x + dx[t];
        int yy = y + dy[t];
        if (xx >= 0 && xx < n && yy >= 0 && yy < m && blocked[xx][yy] == false) {
          adj[calc(xx, yy)].push_back(calc(x, y));   
        }
      }  
    }
  }
  for (int x = 0; x < n; x++) {
    for (int y = 0; y < m; y++) {
      if (blocked[x][y] == false) {
        dfs(calc(x, y));   
      }
    }
  }
  while (store.empty() == false) {
    topo.push_back(store.top()); 
    store.pop(); 
  }
  dp[calc(n - 1, m - 1)] = 1; 
  for (int i = 0; i < (int) topo.size(); i++) {
    if (dp[topo[i]] > 0) {
      int u = topo[i]; 
      for (int j = 0; j < (int) adj[u].size(); j++) {
        int v = adj[u][j]; 
        (dp[v] += dp[u]) %= mod; 
      }
    }
  }
  for (int query = 0; query < q; query++) {
    int x, y;
    cin >> x >> y;
    cout << dp[calc(x - 1, y - 1)] << endl; 
  }
  return 0; 
}