#include <iostream> 
#include <vector> 
#include <string> 
int numTest; 
int dp_size[200005], dp_white[200005]; 
int n; 
std::vector <int> adj[200005]; 

void dfs_size(int u, int father) {
  dp_size[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_size(v, u); 
    dp_size[u] += dp_size[v]; 
  }
}

void dfs_white(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_white(v, u); 
    dp_white[u] += dp_white[v]; 
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      dp_size[i] = 0; 
      dp_white[i] = 0; 
      adj[i].clear(); 
    }                  
    for (int i = 2; i <= n; i++) {
      int parent; 
      std::cin >> parent; 
      adj[i].push_back(parent);
      adj[parent].push_back(i); 
    }
    std::string color; 
    std::cin >> color; 
    for (int i = 0; i < n; i++) {
      if (color[i] == 'W') {
        dp_white[i + 1] = 1; 
      }
    }
    dfs_size(1, -1); 
    dfs_white(1, -1); 
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int numWhite = dp_white[i];
      int numBlack = dp_size[i] - numWhite; 
      if (numWhite == numBlack) {
        ans++; 
      }
    }
    std::cout << ans << std::endl; 
  }
  return 0; 
}