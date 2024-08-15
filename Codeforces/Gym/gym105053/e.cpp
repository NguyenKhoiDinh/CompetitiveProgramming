#include <iostream>
#include <vector> 
int n;
int a[2005]; 
int in[2005], out[2005]; 
std::vector <int> adj[2005]; 
int color[2005]; 
void dfs(int u, int currentColor) {
  color[u] = currentColor; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    if (color[v] == -1) {
      dfs(v, 1 - currentColor); 
    }
    else if (color[v] == color[u]) {
      std::cout << "*";
      exit(0);   
    }
  }
}

int main () {
  std::cin >> n;
  for (int i = 1; i <= 2 * n; i++) {
    std::cin >> a[i];
    if (a[i] > 0) {
      in[a[i]] = i; 
    } 
    else {
      out[-a[i]] = i; 
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (in[i] < in[j] && out[i] < out[j] && out[i] > in[j]) {
        adj[i].push_back(j);
        adj[j].push_back(i); 
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    color[i] = -1; 
  }
  for (int i = 1; i <= n; i++) {
    if (color[i] == -1) {
      dfs(i, 0); 
    }
  }
  for (int i = 1; i <= n; i++) {
    std::cout << (color[i] == 0 ? "G" : "S"); 
  }
  return 0; 
}