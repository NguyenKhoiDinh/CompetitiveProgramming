#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <utility> 
#include <stack>
int f[1000005]; 
std::vector <std::vector <int> > a; 
int n, m; 
int root[1000005]; 
bool visited[1000005]; 
std::stack <int> store;
std::vector <std::vector <int> > adj;  
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}
void dfs(int u) {
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
  store.push(u); 
}
int main () {
  std::cin >> n >> m;
  adj.resize(n * m);
  a.resize(n);
  for (int i = 0; i < n; i++) {
    a[i].resize(m);
    for (int j = 0; j < m; j++) {
      std::cin >> a[i][j]; 
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      root[i * m + j] = i * m + j; 
    }
  }
  for (int i = 0; i < n; i++) {
    std::vector <std::pair <int, int> > v; 
    for (int j = 0; j < m; j++) {
      v.push_back(std::make_pair(a[i][j], i * m + j)); 
    }
    std::sort(v.begin(), v.end()); 
    for (int j = 1; j < m; j++) {
      if (v[j].first == v[j - 1].first) {
        int rootu = findRoot(v[j].second); 
        int rootv = findRoot(v[j - 1].second); 
        if (rootu != rootv) {
          root[rootu] = rootv; 
        }
      }
    }
  }
  for (int j = 0; j < m; j++) {
    std::vector <std::pair <int, int> > v; 
    for (int i = 0; i < n; i++) {
      v.push_back(std::make_pair(a[i][j], i * m + j)); 
    }
    std::sort(v.begin(), v.end()); 
    for (int i = 1; i < n; i++) {
      if (v[i].first == v[i - 1].first) {
        int rootu = findRoot(v[i].second);
        int rootv = findRoot(v[i - 1].second); 
        if (rootu != rootv) {
          root[rootu] = rootv; 
        }
      }
    }
  }
  for (int i = 0; i < n; i++) {
    std::vector <std::pair <int, int> > v; 
    for (int j = 0; j < m; j++) {
      v.push_back(std::make_pair(a[i][j], i * m + j)); 
    }
    std::sort(v.begin(), v.end());
    for (int j = 1; j < m; j++) {
      if (v[j - 1].first < v[j].first) {
        int rootu = findRoot(v[j - 1].second); 
        int rootv = findRoot(v[j].second); 
        adj[rootu].push_back(rootv); 
      }
    } 
  }
  for (int j = 0; j < m; j++) {
    std::vector <std::pair <int, int> > v; 
    for (int i = 0; i < n; i++) {
      v.push_back(std::make_pair(a[i][j], i * m + j)); 
    }
    std::sort(v.begin(), v.end()); 
    for (int i = 1; i < n; i++) {
      if (v[i - 1].first < v[i].first) {
        int rootu = findRoot(v[i - 1].second); 
        int rootv = findRoot(v[i].second); 
        adj[rootu].push_back(rootv); 
      }
    }
  }
  for (int i = 0; i < n * m; i++) {
    if (visited[i] == false) {
      dfs(i); 
    }
  }
  std::vector <int> topo;
  while (store.empty() == false) {
    topo.push_back(store.top());
    store.pop(); 
  }
  for (int i = 0; i < n * m; i++) {
    f[i] = 1; 
  }
  for (int i = 0; i < (int) topo.size(); i++) {
    int u = topo[i];
    for (int j = 0; j < (int) adj[u].size(); j++) {
      int v = adj[u][j]; 
      f[v] = std::max(f[v], f[u] + 1); 
    }
  }
  int ans = -1; 
  for (int i = 0; i < n * m; i++) {
    ans = std::max(ans, f[i]); 
  }
  std::cout << ans; 
  return 0; 
}