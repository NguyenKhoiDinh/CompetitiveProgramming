#include <iostream>
#include <vector> 
#include <algorithm> 
std::vector <int> adj[100005]; 
int n, numQueries; 
int f[100005][20];
int h[100005];  
void dfs(int u, int father) {
  f[u][0] = father; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }  
    h[v] = h[u] + 1;
    dfs(v, u);  
  }
}
int lca(int u, int v) {
  if (h[u] < h[v]) {
    std::swap(u, v); 
  }
  for (int j = 18; j >= 0; j--) {
    if ((h[u] - h[v]) >= (1 << j)) {
      u = f[u][j]; 
    }
  }
  if (u == v) {
    return u; 
  }
  for (int j = 18; j >= 0; j--) {
    if (f[u][j] != -1 && f[v][j] != -1 && f[u][j] != f[v][j]) {
      u = f[u][j];
      v = f[v][j]; 
    }
  }
  return f[u][0]; 
}
int dist(int u, int v) {
  int ancestor = lca(u, v);                                                             
  return h[u] + h[v] - 2 * h[ancestor];  
}

int main () {
  std::cin >> n >> numQueries; 
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  for (int u = 1; u <= n; u++) {
    for (int j = 0; j <= 18; j++) {
      f[u][j] = -1; 
    }
  }
  dfs(1, -1);
  for (int j = 1; j <= 18; j++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][j - 1] != -1) {
        f[u][j] = f[f[u][j - 1]][j - 1]; 
      }
    }
  } 
  for (int query = 1; query <= numQueries; query++) {
    int x, y, z;
    std::cin >> x >> y >> z;
    if (dist(x, z) == dist(x, y) + dist(y, z)) {
      std::cout << "YES" << std::endl; 
    } 
    else {
      std::cout << "NO" << std::endl; 
    }
  }
  return 0; 
}