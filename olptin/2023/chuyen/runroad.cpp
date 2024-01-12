#include <iostream>
#include <vector>
const long long mod = 1000000007LL; 
int n, t; 
int h[200005]; 
std::vector <int> adj[200005]; 
long long ans = 0LL; 
bool visited[200005]; 

long long dfs1(int u, int father, const int &maxHeight) {
  int ret = 1; 
  visited[u] = true; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father || h[v] > maxHeight) {
      continue; 
    }
    ret += dfs1(v, u, maxHeight); 
  }
  return ret; 
}

long long dfs2(int u, int father, const int &numbNodes, long long &total, const int &maxHeight) {
  int ret = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father || h[v] > maxHeight) {
      continue; 
    }
    int numbChild = dfs2(v, u, numbNodes, total, maxHeight); 
    ret += numbChild; 
    long long mul = 1LL; 
    (mul *= numbChild) %= mod;
    (mul *= numbNodes - numbChild) %= mod;
    (mul *= numbNodes - 2) %= mod;
    (total += mul) %= mod; 
  }
  return ret; 
}

long long solve(const int &maxHeight) {
  for (int i = 1; i <= n; i++) {
    visited[i] = false; 
  }  
  long long ret = 0LL; 
  for (int i = 1; i <= n; i++) {
    if (visited[i] == false && h[i] <= maxHeight) {
      int numbChildren = dfs1(i, -1, maxHeight);
      long long total = 0;
      dfs2(i, -1, numbChildren, total, maxHeight);
      (ret += total) %= mod;  
    }
  }
  return ret; 
}

int main () {
  std::cin >> n >> t; 
  for (int i = 1; i <= n; i++) {
    std::cin >> h[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  ans = solve(t); 
  ans -= solve(t - 1); 
  (ans += mod) %= mod;
  std::cout << ans; 
  return 0; 
}