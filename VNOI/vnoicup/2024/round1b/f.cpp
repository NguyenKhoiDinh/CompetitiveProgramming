#include <iostream>
#include <vector> 
std::vector <int> adj[100005]; 
int numPath = 0;
int maxDepth = 0;  
int n, m, k;
void dfs(int u) {
  maxDepth++; 
  if (u == n) {
    numPath++; 
  }
  if (maxDepth == 1000000) {
    numPath = 2;
    return; 
  }
  if (numPath > 1) {
    return; 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (numPath > 1) {
      return; 
    }
    dfs(v); 
  }
}

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    for (int i = 1; i <= m; i++) {
      int u, v;
      std::cin >> u >> v; 
      adj[u].push_back(v); 
    }
    for (int i = 1; i <= k; i++) {
      int p;
      std::cin >> p; 
    }    
    numPath = 0;
    maxDepth = 0;
    dfs(1); 
    if (numPath == 1) {
      std::cout << 0 << std::endl; 
    }                              
    else {
      std::cout << 1 << std::endl; 
    }
  }
  return 0; 
}