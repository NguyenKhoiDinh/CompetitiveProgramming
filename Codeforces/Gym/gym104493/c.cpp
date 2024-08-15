#include <iostream> 
#include <iomanip>
#include <vector> 
std::vector <int> adj[200005]; 
int sz[200005]; 
int n;
int numTest; 
long long ans = 0LL;
void dfs(int u, int father) {
  sz[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u);
    sz[u] += sz[v];
    ans += (long long) sz[v] * (n - sz[v]);  
  }
}

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      sz[i] = 0;
      adj[i].clear(); 
    }
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v; 
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }    
    ans = 0LL; 
    dfs(1, -1);
    double ret = (double) ans / (double) n;
    ret *= 2.0;
    std::cout << std::fixed << std::setprecision(12) << ret << std::endl; 
  }
  return 0; 
}