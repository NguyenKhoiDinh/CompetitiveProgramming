#include <iostream> 
#include <vector> 
int numTest; 
int n;  
std::vector <int> adj[100005]; 
int dist[100005]; 
void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dist[v] = dist[u] + 1; 
    dfs(v, u); 
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n; 
    if (n == 1) {
      std::cout << "Go8" << std::endl; 
      continue; 
    }
    for (int i = 1; i <= n; i++) {
      adj[i].clear();
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);  
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = 0; 
    }
    dfs(1, -1); 
    int maxDist = -1; 
    int farthest = -1; 
    for (int i = 1; i <= n; i++) {
      if (maxDist < dist[i]) {
        maxDist = dist[i];
        farthest = i; 
      }
    }
    for (int i = 1; i <= n; i++) {
      dist[i] = 0; 
    }
    dfs(farthest, -1);
    maxDist = -1;
    for (int i = 1; i <= n; i++) {
      if (maxDist < dist[i]) {
        maxDist = dist[i]; 
      }
    } 
    maxDist++;
    std::cout << (maxDist % 3 == 0 ? "Neodoomer" : "Go8") << std::endl; 
  }
  return 0; 
}