#include <iostream>
#include <vector> 
int numTest; 
std::vector <int> adj[100005]; 
int n;
bool visited[100005];  

void dfs(int u) {
  std::cout << u << ' '; 
  visited[u] = true;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (visited[v] == false) {
      dfs(v);
    }
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      visited[i] = false; 
    }
    for (int i = 1; i <= n / 2; i++) {
      adj[i].push_back(2 * i); 
      adj[2 * i].push_back(i); 
    }
    for (int i = 1; i <= n; i++) {
      if (visited[i] == false) {
        dfs(i); 
      }
    }
    std::cout << std::endl; 
  }
  return 0; 
}