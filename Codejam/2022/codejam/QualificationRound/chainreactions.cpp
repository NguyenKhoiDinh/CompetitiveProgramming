#include <iostream> 
#include <math.h>
#include <vector>
#include <fstream>
#include <algorithm>  
int numTest; 
long long a[100005];
std::vector <int> adj[100005];
int n;  
long long ans = 0LL; 

long long dfs(int u) {
  if ((int) adj[u].size() == 0) {
    return a[u]; 
  }
  std::vector <long long> childs;
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i]; 
    childs.push_back(dfs(v)); 
  }
  std::sort(childs.begin(), childs.end());
  for (int i = 1; i < (int) childs.size(); i++) {
    ans += childs[i]; 
  }
  return std::max(childs[0], a[u]); 
}

int main () {
  //freopen("input.txt", "r", stdin);
  //freopen("output.txt", "w", stdout);
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cout << "Case #" << testCase << ": ";
    std::cin >> n;
    for (int i = 0; i <= n; i++) {
      adj[i].clear(); 
    } 
    for (int i = 1; i <= n; i++) {
      std::cin >> a[i]; 
    }
    for (int i = 1; i <= n; i++) {
      int nxt; 
      std::cin >> nxt; 
      adj[nxt].push_back(i); 
    }
    ans = 0LL;
    ans += dfs(0); 
    std::cout << ans << std::endl; 
  }
  return 0; 
}