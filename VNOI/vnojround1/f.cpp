#include <iostream>
#include <vector>
#include <map>
#include <utility>
int deg[100005]; 
std::vector <int> d; 
std::vector <std::pair <int, int> > adj[100005];
int n;

int main () {
  std::cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v, weight;
    std::cin >> u >> v >> weight; 
    adj[u].push_back(std::make_pair(v, weight)); 
    adj[v].push_back(std::make_pair(u, weight));
    deg[u]++;
    deg[v]++;  
  }
  long long ans = 0LL;  
  int start = -1;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 1) {
      start = i;
      break; 
    }
  }
  int prev = -1;
  while (true) {
    for (int i = 0; i < (int) adj[start].size(); i++) {
      int u = adj[start][i].first; 
      if (u == prev) {
        continue; 
      }
      d.push_back(adj[start][i].second); 
      start = u; 
    }
    if (deg[start] == 1) {
      break; 
    }  
  }
  for (int i = 0; i < (int) d.size(); i++) {
    std::cout << d[i] << "    "; 
  }
  std::cout << std::endl;
  std::vector <long long> f(n + 1, 0LL); 
  for (int i = 0; i < (int) d.size(); i++) {
    ans += f[d[i]]; 
    f[d[i]] += i + 1; 
  }
  std::cout << ans; 
  return 0; 
}