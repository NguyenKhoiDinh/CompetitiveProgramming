#include <bits/stdc++.h>

using namespace std; 
int light[100005]; 
vector <int> adj[100005], rev_adj[100005]; 
int n, k;       
vector <int> listVertex[100005]; 
int state[100005]; 

void dfs(int u, int currentLevel) {
  listVertex[currentLevel].push_back(u); 
  for (int i = 0; i < (int) rev_adj[u].size(); i++) {
    int v = rev_adj[u][i]; 
    dfs(v, currentLevel + 1); 
  }
}

int main () {
  freopen("SOFTWARE.INP", "r", stdin);
  freopen("SOFTWARE.OUT", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> light[i]; 
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v); 
    rev_adj[v].push_back(u);  
  }             
  dfs(1, 0); 
  for (int i = 1; i <= k; i++) {
    int u;
    cin >> u; 
    for (int j = 0; j < (int) adj[u].size(); j++) {
      int v = adj[u][j]; 
      state[v] ^= 1;
    } 
  }
  int ans = light[1]; 
  for (int level = n; level >= 1; level--) {
    for (int i = 0; i < (int) listVertex[level].size(); i++) {
      int u = listVertex[level][i]; 
      if (state[u] == 1 && light[u] == 0) {
        ans++; 
      }
      if (state[u] == 0 && light[u] == 1) {
        ans++; 
      }
      for (int j = 0; j < (int) adj[u].size(); j++) {
        int v = adj[u][j]; 
        state[v] ^= state[u]; 
      }
    }  
  }
  cout << ans; 
  return 0; 
}