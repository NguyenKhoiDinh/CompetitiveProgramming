#include <iostream>
#include <algorithm> 
#include <vector>
#include <math.h> 
struct edge {
  int u, v, c, w; 
  bool operator < (const edge &other) {
    return w < other.w; 
  }
};
int root[1005]; 
int n, m, k; 
std::vector <edge> e; 
int s[12]; 
int findRoot(int u) {
  return root[u] = (u == root[u] ? u : findRoot(root[u])); 
}

int main () {
  int numTest;
  std::cin >> numTest; 
  for (int testCase = 1; testCase <= numTest; testCase++) {
    std::cin >> n >> m >> k;
    e.clear();
    e.resize(m);
    for (int i = 0; i < m; i++) {
      std::cin >> e[i].u >> e[i].v >> e[i].c >> e[i].w; 
    }  
    for (int i = 1; i <= k; i++) {
      std::cin >> s[i]; 
    }
    std::sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) {
      root[i] = i; 
    }
    long long ans = 0LL; 
    for (int i = 0; i < m; i++) {
      int u = e[i].u;
      int v = e[i].v; 
      int rootu = findRoot(u);
      int rootv = findRoot(v); 
      if (rootu != rootv) {
        root[rootu] = rootv; 
        ans += e[i].w; 
      }
    }
    std::cout << ans * 2LL - std::max(0LL, ans - s[1]) << std::endl;  
  }              
  return 0; 
}