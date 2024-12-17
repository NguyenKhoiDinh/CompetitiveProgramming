#include <iostream>     
#include <math.h> 
#include <vector> 
const long long inf = -10000000000000007LL; 
int numTest; 
int n, c; 
long long f[200005][2];
std::vector <int> adj[200005];  
int a[200005];
void dfs(int u, int father) {
  f[u][0] = 0; 
  f[u][1] = a[u];
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }           
    dfs(v, u);
    f[u][0] += std::max(f[v][0], f[v][1]);
    f[u][1] += std::max(f[v][0], f[v][1] - 2LL * c);   
  } 
} 

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> c;
    for (int i = 1; i <= n; i++) {
      adj[i].clear(); 
      f[i][0] = f[i][1] = inf; 
      std::cin >> a[i]; 
    } 
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    dfs(1, -1);
    std::cout << std::max(f[1][0], f[1][1]) << std::endl; 
  }
  return 0; 
}