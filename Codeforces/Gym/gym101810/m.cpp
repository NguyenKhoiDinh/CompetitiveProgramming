#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <math.h> 
int numTest; 
int n, numQueries;
struct edge {
  int v, w1, w2; 
}; 
std::vector <edge> adj[100005];
int f[100005][18];
int sum1[100005][18], sum2[100005][18];
int H[100005];  
void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    edge neighbor = adj[u][i]; 
    int v = neighbor.v; 
    int w1 = neighbor.w1; 
    int w2 = neighbor.w2; 
    if (v == father) {
      continue; 
    }
    f[v][0] = u; 
    sum1[v][0] = w1;
    sum2[v][0] = w2; 
    H[v] = H[u] + 1;  
    dfs(v, u); 
  }
}
void init() {
  for (int j = 1; j <= 17; j++) {
    for (int u = 1; u <= n; u++) {
      if (f[u][j - 1] != -1) {
        f[u][j] = f[f[u][j - 1]][j - 1];
        if (f[u][j] != -1) {
          sum1[u][j] = sum1[f[u][j - 1]][j - 1] + sum1[u][j - 1];  
          sum2[u][j] = sum2[f[u][j - 1]][j - 1] + sum2[u][j - 1]; 
        }
      }
    }
  }
}
std::pair <int, int> lca(int u, int v) {  
  int ret = 0;
  if (H[u] > H[v]) {
    for (int j = 17; j >= 0; j--) {
      if (H[u] - (1 << j) >= H[v]) {
        ret += sum2[u][j]; 
        u = f[u][j]; 
      }
    }  
  }
  else {
    for (int j = 17; j >= 0; j--) {
      if (H[v] - (1 << j) >= H[u]) {
        ret += sum1[v][j];
        v = f[v][j]; 
      }
    }
  }
  if (u == v) {
    return std::make_pair(ret, u); 
  }
  for (int j = 17; j >= 0; j--) {
    if (f[u][j] != -1 && f[v][j] != -1 && f[u][j] != f[v][j]) {
      ret += sum1[v][j];
      ret += sum2[u][j]; 
      u = f[u][j];
      v = f[v][j];   
    }
  }
  ret += sum1[v][0];
  ret += sum2[u][0];
  return std::make_pair(ret, f[u][0]); 
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
      H[i] = 0;  
    }
    long long total = 0LL; 
    for (int i = 1; i < n; i++) {
      int u, v, w1, w2;
      std::cin >> u >> v >> w1 >> w2; 
      total += w1; 
      total += w2; 
      adj[u].push_back((edge) {v, w2, w1}); 
      adj[v].push_back((edge) {u, w1, w2}); 
    }
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < 18; j++) {
        f[i][j] = -1;
        sum1[i][j] = 0;
        sum2[i][j] = 0;  
      }
    }
    dfs(1, -1);
    init();
    std::cin >> numQueries;
    for (int query = 1; query <= numQueries; query++) {
      int u, v;
      std::cin >> u >> v; 
      std::pair <int, int> e = lca(u, v); 
      std::cout << total - e.first << std::endl; 
    }  
  }
  return 0; 
}