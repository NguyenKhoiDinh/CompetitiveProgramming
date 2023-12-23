#include <iostream> 
#include <vector> 
#include <map> 
#include <utility>
int numTest; 
int sz[200005]; 
std::vector <int> adj[200005]; 
std::map <std::pair <int, int>, int> id; 
int n; 
std::vector <int> ans; 
bool canSplit = true; 

void dfs(int u, int father) {
  if (canSplit == false) {
    return; 
  }
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u); 
    sz[u] += sz[v]; 
  }
  if (sz[u] == 3) {
    sz[u] = 0;
    if (father != -1) {
      ans.push_back(id[std::make_pair(father, u)]); 
    }  
  }
  else if (sz[u] > 3) {
    canSplit = false; 
    return; 
  }
}

int main () {
  std::cin >> numTest;
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
      sz[i] = 1;
      adj[i].clear();   
    }
    canSplit = true;
    ans.clear(); 
    id.clear();  
    for (int i = 1; i < n; i++) {
      int u, v;
      std::cin >> u >> v;
      adj[u].push_back(v);
      adj[v].push_back(u); 
      id[std::make_pair(u, v)] = i; 
      id[std::make_pair(v, u)] = i; 
    }
    dfs(1, -1); 
    if (sz[1] != 0) {
      canSplit = false; 
    }
    if (canSplit == true) {
      std::cout << (int) ans.size() << std::endl; 
      for (int i = 0; i < (int) ans.size(); i++) {
        std::cout << ans[i] << ' '; 
      }
      std::cout << std::endl;
    }
    else {
      std::cout << -1 << std::endl;
    }
  }
  return 0; 
}