#include <iostream> 
#include <math.h>
#include <algorithm>
#include <vector>
int n, m, numQueries; 
std::vector <int> adj[100005], adj_tree[100005]; 
int low[100005], numb[100005]; 
int timeDfs = 0;
int value[100005]; 
int chainIndex[100005];
int chainStart[100005]; 
int sz[100005];               
int chain = 1;
std::vector <int> listVertex; 
int position[100005];  
int bridges = 0; 
int f[100005][18]; 

void dfs(int u, int father) {
  sz[u] = 1; 
  numb[u] = low[u] = ++timeDfs; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (numb[v] == 0) {
      adj_tree[u].push_back(v);
      adj_tree[v].push_back(u);
      dfs(v, u);
      sz[u] += sz[v];  
      low[u] = std::min(low[u], low[v]); 
      if (low[v] == numb[v]) {
        value[v] = 1; 
        bridges++; 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
}

void heavyLightDecomposition(int u, int father) {
  if (chainStart[chain] == -1) {
    chainStart[chain] = u;
  }  
  chainIndex[u] = chain; 
  listVertex.push_back(u); 
  position[u] = (int) listVertex.size();               
  int specialVertex = -1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj_tree[u][i]; 
    if (v == father) {
      continue; 
    }
    if (specialVertex == -1 || sz[specialVertex] < sz[v]) {
      specialVertex = v; 
    }
  }
  if (specialVertex != -1) {
    heavyLightDecomposition(specialVertex, u); 
  }
  for (int i = 0; i < (int) adj_tree[u].size(); i++) {
    int v = adj_tree[u][i]; 
    if (v == father) {
      continue; 
    }
    if (v != specialVertex) {
      chain++; 
      heavyLightDecomposition(v, u); 
    }
  }
}

void initLCA() {
  for (int j = 1; j <= 17; j++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][j - 1] == -1) {
        continue; 
      }
      f[u][j] = f[f[u][j - 1]][j - 1]; 
    }
  }
}
 
int lca(int u, int v) {
  if (dist[u] < dist[v]) {
    std::swap(u, v); 
  }
  for (int k = 17; k >= 0; k--) {
    if (dist[u] - (1 << k) >= dist[v]) {
      u = f[u][k]; 
    }
  }
  if (u == v) {
    return u; 
  }
  for (int k = 17; k >= 0; k--) {
    if (f[u][k] != -1 && f[u][k] != f[v][k]) {
      u = f[u][k];
      v = f[v][k]; 
    }
  }
  return f[u][0]; 
}

int main () {
  freopen("bridge.inp", "r", stdin);
  freopen("bridge.out", "w", stdout);
  std::cin >> n >> m >> numQueries; 
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v; 
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  dfs(1, -1); 
  heavyLightDecomposition(1, -1); 
  for (int query = 1; query <= numQueries; query++) {
    
  }
  return 0; 
}