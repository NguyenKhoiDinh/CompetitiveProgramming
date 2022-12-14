#include <bits/stdc++.h>

using namespace std;
const long long mod = 1000000007;
long long dp[100005][2]; 
int n; 
vector <int> adj[100005];

void dfs(int u, int father) {
  dp[u][0] = 1LL; 
  dp[u][1] = 1LL; 
  for (int i = 0; i < (int) adj[u].size(); i++) {
    int v = adj[u][i];
    if (v == father) {
      continue; 
    }
    dfs(v, u);
    (dp[u][0] *= (dp[v][1] + dp[v][0]) % mod) %= mod; 
    (dp[u][1] *= dp[v][0]) %= mod; 
  }
}

int main () {
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u); 
  }
  dfs(1, -1); 
  cout << (dp[1][0] + dp[1][1]) % mod; 
  return 0;
}