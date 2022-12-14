#include <iostream> 
#include <vector>
#include <math.h>  
int n, m; 
std::vector <int> adj[10005]; 
int low[10005], numb[10005]; 
bool check[10005]; 
bool visited[10005]; 
int timeDFS = 0, bridge = 0; 

void dfs(int u, int father) {
  int child = 0; 
  low[u] = numb[u] = ++timeDFS; 
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (v == father) {
      continue; 
    }
    if (visited[v] == false) {
      dfs(v, u);         
      low[u] = std::min(low[u], low[v]); 
      if (low[v] == numb[v]) {
        bridge++; 
      }
      child++; 
      if (father == -1) {
        if (child > 1) {
          check[u] = true; 
        }
      }
      else if (low[v] >= numb[u]) {
        check[u] = true; 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
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
  }
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false) {
      dfs(i, -1); 
    }
  }
  int cntJoint = 0; 
  for (int i = 1; i <= n; i++) {
    if (check[i] == true) {
      cntJoint++; 
    }
  }
  std::cout << cntJoint << " " << bridge; 
  return 0; 
}