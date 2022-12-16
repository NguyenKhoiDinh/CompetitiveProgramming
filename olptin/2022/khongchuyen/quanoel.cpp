#include <iostream>
#include <math.h>
#include <vector>
std::vector <int> adj[100005]; 
int n, m; 
int deg[100005];
bool visited[100005];  
int ans = 0; 
int totalDeg = 0; 
int numbVertex = 0; 

void dfs(int u) {
  totalDeg += deg[u];
  numbVertex++; 
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v); 
    }
  }
}

int main () {
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++; 
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      totalDeg = 0; 
      numbVertex = 0;
      dfs(i);
      ans += std::min(numbVertex, totalDeg / 2);  
    }   
  }
  std::cout << ans;
  return 0; 
}