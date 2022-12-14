#include <bits/stdc++.h>

using namespace std;
const int MAX_N = 105; 
const int MAX_M = 2005;
int dp[MAX_N][MAX_M];
vector <int> adj[MAX_N]; 
int n, m; 
int cost[MAX_N], gold[MAX_N]; 

void dfs(int u, int father) {
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue;
    }
    dfs(v, u);
    for (int j = m; j >= 0; j--) {
      if (j >= cost[v]) {
        dp[u][j] = max(dp[u][j], dp[v][j - cost[v]] + gold[u]); 
      }  
    }
  }
}

int main () {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    cin >> gold[i];
  }
  for (int i = 2; i <= n; i++) {
    cin >> cost[i];
  }
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, -1);
  int ans = -1;
  for (int j = 1; j <= m; j++) {
    ans = max(ans, dp[1][j]);
  }
  cout << ans;
  return 0; 
}