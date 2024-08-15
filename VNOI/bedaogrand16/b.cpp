#include <iostream>
#include <stack>
#include <math.h> 
#include <vector>
#include <utility>
int n, m;
std::vector <std::pair <int, int> > adj[200005];
std::vector <std::pair <int, int> > adj_root[200005];  
long long cost[200005], f[200005]; 
int root[200005];
bool deleted[200005];
int low[200005], numb[200005];
std::stack <int> store;
std::stack <int> topo;
bool visited[200005];
int timeDfs = 0;
struct edge {
  int u, v, w; 
}; 
edge e[200005]; 
void dfs(int u) {
  timeDfs++; 
  numb[u] = timeDfs;
  low[u] = timeDfs; 
  store.push(u); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    std::pair <int, int> neighbor = adj[u][i]; 
    int v = neighbor.first; 
    if (deleted[v] == true) {
      continue;
    }
    if (numb[v] == 0) {
      dfs(v); 
      low[u] = std::min(low[u], low[v]); 
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }
  if (low[u] == numb[u]) { 
    do {
      int v = store.top(); 
      store.pop(); 
      deleted[v] = true; 
      root[v] = u;               
      if (v == u) {
        break; 
      }
    }
    while (true);
  }
}
void dfs_topo(int u) {
  visited[u] = true; 
  for (int i = 0; i < (int) adj_root[u].size(); i++) {
    int v = adj_root[u][i].first;
    if (visited[v] == false) {
      dfs_topo(v); 
    }  
  }
  topo.push(u); 
}
int main () {         
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v, w;
    std::cin >> u >> v >> w;
    adj[u].push_back(std::make_pair(v, w)); 
    e[i] = (edge) {u, v, w}; 
  }
  for (int i = 1; i <= n; i++) {
    if (deleted[i] == false) {
      dfs(i); 
    }
  }
  for (int i = 1; i <= m; i++) {
    int u = e[i].u;
    int v = e[i].v;
    int w = e[i].w;
    if (root[u] == root[v]) {
      while (w > 0) {
        cost[root[u]] += w;
        w /= 2; 
      }
    }
    else {                                       
      adj_root[root[u]].push_back(std::make_pair(root[v], w)); 
    } 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs_topo(i); 
    }
  }
  std::vector <int> v; 
  while (topo.empty() == false) {
    v.push_back(topo.top());
    topo.pop(); 
  }
  for (int i = 1; i <= n; i++) {
    f[i] = -1; 
  }
  f[root[1]] = cost[root[1]]; 
  for (int i = 0; i < (int) v.size(); i++) {
    int u = v[i];
    if (f[u] == -1) {
      continue; 
    }
    for (int j = 0; j < (int) adj_root[u].size(); j++) {
      std::pair <int, int> neighbor = adj_root[u][j]; 
      int to = neighbor.first;
      int w = neighbor.second; 
      f[to] = std::max(f[to], f[u] + w + cost[to]);
    }
  }
  long long ans = -1;
  for (int i = 1; i <= n; i++) {
    ans = std::max(ans, f[i]); 
  }
  std::cout << ans; 
  return 0; 
}