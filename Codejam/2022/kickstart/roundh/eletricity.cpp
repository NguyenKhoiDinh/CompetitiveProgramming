#include <iostream> 
#include <vector>
#include <math.h>
int numTest; 
int n; 
int a[200005]; 
int dp_out[200005], dp_in[200005]; 
std::vector <int> adj[200005];
int parent[200005]; 

void dfs_out(int u, int father) {
  parent[u] = father; 
  dp_out[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs_out(v, u); 
    if (a[u] > a[v]) {
      dp_out[u] += dp_out[v]; 
    }
  }
} 

void dfs_in(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (a[u] < a[v]) {
      dp_in[v] = dp_in[u] + dp_out[u]; 
    }
    dfs_in(v, u); 
  }  
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    } 
    for (int i = 1; i <= n; i++) {
      dp_out[i] = 0; 
      dp_in[i] = 0;   
      adj[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    dfs_out(1, -1); 
    dfs_in(1, -1);
    int ans = 0; 
    for (int i = 1; i <= n; i++) {
      int father = parent[i]; 
      int numb = dp_out[i] + dp_in[i]; 
      ans = std::max(ans, numb);   
    } 
    std::cout << ans << std::endl; 
  }
  return 0; 
}