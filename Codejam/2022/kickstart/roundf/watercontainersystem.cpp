#include <iostream> 
#include <vector>
int numTest; 
std::vector <int> adj[1000005];
int cnt[1000005];
int n, numbAdd; 

void dfs(int u, int father, int distance) {
  cnt[distance]++;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u, distance + 1); 
  }                          
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n >> numbAdd;
    for (int i = 0; i <= n; i++) {
      adj[i].clear(); 
      cnt[i] = 0; 
    } 
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
    }
    for (int i = 1; i <= numbAdd; i++) {
      int container;
      std::cin >> container;
    }
    dfs(1, -1, 0);
    int ans = 0; 
    for (int i = 0; i < n; i++) {
      if (numbAdd >= cnt[i]) {
        ans += cnt[i];
        numbAdd -= cnt[i]; 
      }
      else {
        break;
      } 
    }            
    std::cout << ans << std::endl;
  }
  return 0; 
}