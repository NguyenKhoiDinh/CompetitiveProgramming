#include <iostream>
#include <vector>
#include <math.h>  
int numTest; 
std::vector <int> adj[100005]; 
int low[100005]; 
int numb[100005]; 
int n, m; 
int timeDfs = 0; 
int cnt[100005];
long long ans = 0LL; 

void dfs(int u, int father) {
  timeDfs++;
  low[u] = timeDfs;
  numb[u] = timeDfs;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (numb[v] == 0) {
      dfs(v, u); 
      low[u] = std::min(low[u], low[v]); 
      cnt[u] += cnt[v]; 
      if (low[v] == numb[v]) {
        ans = std::max(ans, 1LL * cnt[v] * (n - cnt[v])); 
      }
    }
    else {
      low[u] = std::min(low[u], numb[v]); 
    }
  }  
} 

int main () {
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      low[i] = 0;
      numb[i] = 0; 
      adj[i].clear();
      cnt[i] = 1;  
    }  
    timeDfs = 0; 
    for (int i = 1; i <= m; i++) {
      int u, v;
      std::cin >> u >> v; 
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    ans = 0LL; 
    dfs(1, -1);
    ans = 1LL * n * (n - 1) / 2 - ans;
    std::cout << ans << std::endl; 
  }
  return 0; 
}