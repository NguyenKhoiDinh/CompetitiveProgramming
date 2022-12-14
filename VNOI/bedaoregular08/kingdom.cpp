#include <iostream>
#include <algorithm>
#include <vector>

std::vector <int> adj[1000005];
int n;
int color[1000005];
int currentColor = -1;
bool check = true; 
std::vector <int> ans; 

void dfs(int u, int father) {
  if (check == false) {
    return;
  }
  if (color[u] != currentColor) {
    check = false;
    return; 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dfs(v, u); 
  }
}

void process(int u) {
  check = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];          
    currentColor = color[v];
    dfs(v, u); 
  }
  if (check == true) {
    ans.push_back(u); 
  }
}

int main () {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL); 
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> color[i];
  }
  for (int i = 1; i <= n; i++) {
    int u = i;
    for (int j = 0; j < (int) adj[u].size(); j++) {
      int v = adj[u][j];
      if (color[u] == color[v]) {
        continue; 
      }
      if (u > v) {
        std::swap(u, v); 
      }
      process(u);
      process(v);       
      if (ans.empty() == true) {
        std::cout << "NO"; 
      }
      else {
        std::cout << "YES" << std::endl; 
        for (int x = 0; x < (int) ans.size(); x++) {
          std::cout << ans[x] << ' '; 
        }
      }
      return 0; 
    }
  }
  std::cout << "YES" << std::endl;
  for (int i = 1; i <= n; i++) {
    std::cout << i << ' '; 
  }
  return 0;
}