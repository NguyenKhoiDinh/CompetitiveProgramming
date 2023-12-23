#include <iostream> 
#include <set>
#include <vector>
#include <utility> 
int n, m, numQueries; 
int ans[100005]; 
std::set <std::pair <int, int> > myset[100005]; 
std::vector <int> adj[100005]; 
int lang[100005]; 

void dfs(int u, int father) {
  std::pair <int, int> pr = std::make_pair(lang[u], 1); 
  myset[u].insert(pr); 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
    if ((int) myset[u].size() < (int) myset[v].size()) {
      myset[u].swap(myset[v]); 
    }
    for (std::set <std::pair <int, int> >::iterator it = myset[v].begin(); it != myset[v].end(); it++) {
      
    }
  }
}

int main () {
  std::cin >> n >> m >> numQueries; 
  for (int i = 1; i < n; i++) {
    int boss;
    std::cin >> boss;
    adj[boss].push_back(i + 1);
    adj[i + 1].push_back(boss);
  }
  for (int i = 1; i <= n; i++) {
    std::cin >> lang[i]; 
  }
  dfs(1, -1); 
  for (int query = 1; query <= numQueries; query++) {
    int u;
    std::cin >> u;
    std::cout << ans[u] << std::endl; 
  }
  return 0; 
}