#include <iostream>
#include <vector>
const long long mod = 1000000007LL; 
long long power2[100005];
int n, m;
std::vector <int> adj[100005];  
int state[100005]; 
int cnt = 0; 
 
void init() {
  power2[0] = 1LL;
  for (int i = 1; i <= 100000; i++) {
    power2[i] = (power2[i - 1] * 2LL) % mod; 
  }
}
 
void dfs(int u, int father) {
  state[u] = 1; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    if (state[v] == 0) {
      dfs(v, u); 
    }
    else if (state[v] == 1) {
      cnt++; 
    }
  }
  state[u] = 2;
}
 
int main () {
  init(); 
  std::cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    int u, v;
    std::cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long ans = 1LL; 
  for (int i = 1; i <= n; i++) {
    if (state[i] == 0) {
      cnt = 0;
      dfs(i, -1); 
      (ans *= power2[cnt]) %= mod; 
    }
  }
  std::cout << ans; 
  return 0; 
}